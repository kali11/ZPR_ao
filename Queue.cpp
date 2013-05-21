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
	if(queue.size() > 0) cout << queue.size();
	if(!queue.empty())
	{
		cout << "nie pusta" << endl;
		Request *req = queue.front();
		queue.pop_back();
		return req;
	}
	return NULL;

}

void Queue::add(Request *req)
{
	boost::mutex::scoped_lock scoped_lock(qmutex);
	cout << queue.size() << endl;
	queue.push_back(req);
	cout << queue.size() << endl;
}
