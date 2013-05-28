#include "Logproxy.h"

Logproxy::Logproxy()
{
	scheduler = Scheduler::getInstance();
}
string Logproxy::read()
{
	return "read";
}


void Logproxy::write(string s)
{
	boost::function<void (void)> f;
	f = boost::bind(&Logger::write, &logger, s);

	boost::function<bool (void)> g;
	g = boost::bind(&Logger::canWrite, &logger);

	Request *req = new Request();
	req->load(f);
	req->loadGuard(g);
	scheduler->enqueue(req);
}