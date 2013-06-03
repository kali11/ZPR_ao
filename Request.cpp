#include "Request.h"

Request::Request()
{
	baseGuard = new RequestBase();
}
/*
Request::Request(boost::promise<boost::any> *p)
{
	baseGuard = new RequestBase();
	promise = p;
}
*/
Request::~Request()
{
	delete baseGuard;
}

void Request::call()
{
	base->callFun();
}

bool Request::guard()
{
	return baseGuard->callGuard();
}