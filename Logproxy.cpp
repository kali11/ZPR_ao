#include "Logproxy.h"

Logproxy::Logproxy()
{
	scheduler = Scheduler::getInstance();
}
boost::unique_future<string> Logproxy::read()
{
	boost::promise<string> prom;
	boost::unique_future<string> fut = prom.get_future();
	boost::function<std::string (void)> fr = NULL;
	fr = boost::bind(&Logger::read, &logger);

	Request *req = new Request(&prom);
	req->load(fr);
	scheduler->enqueue(req);

	return std::move(fut);
}


void Logproxy::write(string s)
{
	boost::function<void (void)> f = NULL;
	f = boost::bind(&Logger::write, &logger, s);

	boost::function<bool (void)> g;
	g = boost::bind(&Logger::canWrite, &logger);

	Request *req = new Request();
	req->load(f);
	req->loadGuard(g);
	scheduler->enqueue(req);
}