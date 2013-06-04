#include "Scheduler.h"

Scheduler* Scheduler::pInstance_ = NULL;
volatile bool Scheduler::finish_;


Scheduler::~Scheduler()
{
	
}

Scheduler* Scheduler::getInstance(unsigned int n)
{
	if(!pInstance_)
		pInstance_ = new Scheduler(n);
	return pInstance_;
}


Scheduler::Scheduler(unsigned int n)
{
	//thrd = new boost::thread(*this);
	maxThreads_ = n;
	n_ = 0;
}

Scheduler::Scheduler(const Scheduler & s)
{
}

void Scheduler::operator()()
{
	while(!finish_)
	{
		mutex_.lock();
		if(n_ == maxThreads_) 
		{
			mutex_.unlock();
			boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
		}
		else 
		{
			mutex_.unlock();
			Request *req = queue.get();
			if(req) 
			{
				if(req->guard())
				{
					mutex_.lock();
					++n_;
					mutex_.unlock();
					//calling function given by request in separate thread
					boost::thread thread(&Scheduler::call, this, req);
					threads.push_back(&thread);
				}
				else
				{
					queue.add(req);
				}

			}
		}
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

void Scheduler::call(Request* req)
{
	req->call();
	mutex_.lock();
	--n_;
	mutex_.unlock();
}