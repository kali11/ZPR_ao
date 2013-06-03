#include "Queue.h"

Queue::Queue()
{
}

Queue::~Queue()
{
	for(vector<Request*>::iterator it = queue.begin(); it != queue.end(); ++it)
	{
		delete *it;
	}
	queue.clear();
}

Request* Queue::get()
{
	boost::mutex::scoped_lock scoped_lock(qmutex);
	if(!queue.empty())
	{
		Request *req = queue.front();
		queue.erase(queue.begin());
		return req;
	}
	return NULL;

}

void Queue::add(Request *req)
{
	boost::mutex::scoped_lock scoped_lock(qmutex);
	queue.push_back(req);
}
