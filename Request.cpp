#include "Request.h"

Request::Request()
{
}

Request::~Request()
{
}

void Request::call()
{
	base->callFun();
}