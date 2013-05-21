#ifndef SCHEDULER
#define SCHEDULER

#include "Queue.h"
#include <boost/thread.hpp>

/**
* Scheduler class, responsible for calling requests. Singleton class, works in a separate thread. 
* Object of this class must be created in main function, before other threads.
*
*/
class Scheduler
{
public:
	/**
	* Public copy constructor! It is not in a singleton style, but it is needed to cerate a thread
	*/
	Scheduler(const Scheduler & s);
	~Scheduler();

	/**
	* Get pointer to Scheduler instance
	* @return pointer to Scheduler object
	*/
	static Scheduler* getInstance();

	/**
	* Insert a request to the queue. Insertion is protected by mutex.
	* @param req Request object
	*/
	void enqueue(Request *req);

	/**
	* Here is main execution in a loop
	*/
	void operator()();

	/**
	* Force a thread to finish as soon as possible
	*/
	void finish();

	
	
private:
	
	/**
	* Class private constructor
	*/
	Scheduler();
	Queue queue;
	static Scheduler* pInstance_;
	static volatile bool finish_; //Flaga - zg³oszenie przerwania
	boost::mutex qmutex;
	
};

#endif