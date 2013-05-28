#include "Request.h"

Request::Request()
{
	baseGuard = new RequestBase();
}

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