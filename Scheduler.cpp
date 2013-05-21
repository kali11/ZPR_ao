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
	//thrd = new boost::thread(*this);
}

Scheduler::Scheduler(const Scheduler & s)
{
}

void Scheduler::operator()()
{
	while(!finish_)
	{
		Request *req = queue.get();
		if(req) {cout << "wykonuje" << endl; req->call();}
	}
}

void Scheduler::finish()
{
	finish_ = true;
}

void Scheduler::enqueue(Request *req)
{
	cout << "ddoaje" << endl;
	queue.add(req);
}

