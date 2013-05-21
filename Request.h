#ifndef REQUEST
#define REQUEST
#include <iostream>

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
	* Load the request, prepare it for futer call
	*/
	template <typename T>
	void load(T f)
	{
		base = new RequestHolder<decltype(f)>(f);
	}
	
private:
	/*
	* Just base, abstract class, needed to hold pointer to the RequestHolder in Request class;
	*/
	class RequestBase 
	{
	public:
		/**
		* pure virtual method
		*/
		virtual void callFun() = 0;
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
		virtual void callFun(){fun(); };
		R fun;
	};
	
	RequestBase *base;
	
};

#endif