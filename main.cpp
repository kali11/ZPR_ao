#include <iostream>
#include <boost/regex.hpp>
#include <iterator>
#include <algorithm>
#include "Queue.h"

using namespace std;
int main(int argc,char *argv[])
{
	Request * req;
	Queue * q = new Queue();
	//cout << "jesli to sie wyswietla tzn, ze dziala boost" << endl;
	for(int i = 0; i < 5; ++i)
	{
		req = new Request();
		q->add(req);
	}
	delete q;
	system("PAUSE");
	return 0;
}