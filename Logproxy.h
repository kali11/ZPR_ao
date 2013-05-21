#ifndef LOGPROXY
#define LOGPROXY
#include <iostream>
#include "Logger.h"
#include "Request.h"
#include "Scheduler.h"
#include <boost/function.hpp>
#include <boost/bind.hpp>

using namespace std;
/**
* Proxy class for logger. Must have the same interface.
*/
class Logproxy
{
public:
	Logproxy();
	string read();
	/**
	* Bind Logger method with parameters and add request to the scheduler's queue
	* @param string 
	*/
	void write(string s);

private:
	Logger logger;
	Scheduler *scheduler;
};

#endif