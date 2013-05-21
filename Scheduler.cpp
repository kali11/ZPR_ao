#include "Scheduler.h"

Scheduler* Scheduler::pInstance_ = NULL;
volatile bool Scheduler::finish_;


Scheduler::~Scheduler()
{
}

Scheduler* Scheduler::getInstance()
{
	if(!pInstance_)
		pInstance_ = new Scheduler();
	return pInstance_;
}


Scheduler::Scheduler()
{
	thrd = new boost::thread(*this);
}

Scheduler::Scheduler(const Scheduler & s)
{
}

void Scheduler::join()
{
	thrd->join();
}

void Scheduler::operator()()
{
	while(!finish_)
	{
		Request *req = queue.get();
		if(req) req->call();
	}
}

void Scheduler::finish()
{
	finish_ = true;
}

void Scheduler::enqueue(Request *req)
{
	queue.add(req);
}

