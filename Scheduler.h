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
	* Public copy constructor! It is not in a singleton style, but it is needed to create a thread
	*/
	Scheduler(const Scheduler & s);
	~Scheduler();

	/**
	* Get pointer to Scheduler instance
	* @return pointer to Scheduler object
	*/
	static Scheduler* getInstance(unsigned int n = 1);

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
	Scheduler(unsigned int n);

	/**
	* Calls function specified by request and changes number of pending threads.
	* This function is always called in separate thread
	*/
	void call(Request * req);

	Queue queue;
	static Scheduler* pInstance_;
	static volatile bool finish_; //Flaga - zg³oszenie przerwania
	unsigned int maxThreads_;
	vector<boost::thread*> threads;
	/**
	* current number of pending threads
	*/
	unsigned int n_;
	boost::mutex mutex_;
	
};
#endif