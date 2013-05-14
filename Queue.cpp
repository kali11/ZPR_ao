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
	return NULL;
}

void Queue::add(Request *req)
{
	queue.push_back(req);
}
