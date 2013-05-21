#ifndef QUEUE
#define QUEUE
#include "Request.h"
#include <vector>
#include <boost/thread.hpp>

using namespace std;

/**
* Class represents queue of Requests. Acces to the queue is synchronized.
*/
class Queue
{
public:
	/**
	* Constructor
	*/
	Queue();
	/**
	* Get request - first in the queue
	* @return Request*
	*/
	Request* get();

	/**
	* Add request at the end of the queue
	* @param Request*
	*/
	void add(Request* req);

	/**
	* Destructor
	*/
	~Queue();
private:
	boost::mutex qmutex;
	vector<Request*> queue;
};

#endif