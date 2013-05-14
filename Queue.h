#ifndef QUEUE
#define QUEUE
#include "Request.h"
#include <vector>

using namespace std;

class Queue
{
public:
	Queue();
	Request* get();
	void add(Request* req);
	~Queue();
private:
	vector<Request*> queue;
};

#endif