#ifndef REQUEST
#define REQUEST
#include <iostream>
#include <boost/any.hpp>
#include <boost/thread.hpp>

using namespace std;

/**
* Request class that represents call request for servant
*/
class Request
{
public:
	Request();

	template<typename PROM>
	Request(boost::promise<PROM> *p)
	{
		baseGuard = new RequestBase();
		//promBase = new PromiseHolder<PROM>();
		PromiseHolder<PROM> ph;
		ph.promise = p;

		boost::function<void (PROM)> setf;
		//void (&fun)(PROM) = PromiseHolder<PROM>::setValue;
		//void (&fun)(PROM) = ph.setValue;
		//setf = boost::bind((void(PromiseHolder::*)(PROM&))&PromiseHolder::setValue, &ph, _1);
		boost::bind<PROM>(PromiseFunctor(), "sdfsdfsd", ph)();
		//boost::bind<PROM>(PromiseFunctor(), "ssss", ph)();
		//UnaryFunction<PROM>::type func = boost::bind(&setValue<PROM>, "qwewqe", p);
		//boost::promise<PROM>* pr = promBase->getPromise();
		//pr = p;
		//pr->set_value("dg");
		
	}

	template<typename X>
	void setValue(X val, boost::promise<X>* p)
	{
		p->set_value(val);
	}




	~Request();
	/**
	* Make request call
	*/
	void call();

	/**
	* call guard method
	*/
	bool guard();

	/**
	* Load the request, prepare it for future call
	*/
	template <typename T1>
	void load(T1 f)
	{
		base = new RequestHolder<decltype(f)>(f);
	}

	/**
	* Load the guard method, which checks if a request can be executed. 
	* Using this method is optional - use only for requests that need synchronization.
	*/
	template <typename T2>
	void loadGuard(T2 f)
	{
		baseGuard = new GuardHolder<decltype(f)>(f);
	}
	
private:
	/*
	* Just base class, needed to hold pointer to the RequestHolder in Request class;
	*/
	class RequestBase 
	{
	public:
		/**
		* virtual methods
		*/
		virtual void callFun() {}
		virtual bool callGuard() {return true;}
	};

	/**
	* template class, holder for the request. Type is a boost::function object, defined in Proxy class.
	* 
	*/
	template <typename R>
	class RequestHolder : public RequestBase
	{
	public:
		RequestHolder() {}
		RequestHolder(R r) : fun(r) {}
		/**
		* Here we exactly make a call on a Servant
		*/
		virtual void callFun()
		{
			fun();
		}
		R fun;
	};

	/**
	* template class, holder for the guard method. Type is a boost::function object, defined in Proxy class.
	* 
	*/
	template <typename P>
	class GuardHolder : public RequestBase
	{
	public:
		GuardHolder() {}
		GuardHolder(P r) : guard(r) {}
		/**
		* Here we exactly make a call on a Servant
		*/
		virtual bool callGuard(){return guard(); }
		P guard;
	};
	
	class PromiseBase
	{
	public:
		virtual void setValue() {}
	};

	template <typename PROM>
	class PromiseHolder// : public PromiseBase
	{
	public:
		//PromiseHolder() {cout << "nowy promise" << endl;}
		void setValue(PROM val)
		{
			promise->set_value(val);
		}
		boost::promise<PROM>* promise;
	};

	class PromiseFunctor 
	{
		public:

		template<typename ARG1, typename ARG2>
		ARG1 operator()(ARG1 arg1, PromiseHolder<ARG2> pr) 
		{
			pr.setValue(arg1);
			return arg1;
		}
	};
	

	RequestBase *base;
	RequestBase *baseGuard;
	PromiseBase *promBase;
	//boost::promise<boost::any>* promise;
};

#endif