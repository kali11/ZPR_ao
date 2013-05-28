#ifndef REQUEST
#define REQUEST
#include <iostream>
#include <boost/any.hpp>

using namespace std;

/**
* Request class that represents call request for servant
*/
class Request
{
public:
	Request();
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
		virtual void callFun(){fun(); }
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
	
	RequestBase *base;
	RequestBase *baseGuard;

};

#endif