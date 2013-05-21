#include <iostream>
#include <boost/regex.hpp>
#include <iterator>
#include <algorithm>
#include "Queue.h"
#include "Scheduler.h"
#include "Request.h"
#include "Logger.h"

using namespace std;
void test(string i)
{
	cout << "test " << endl;
	cout << i << endl;
}

template <class T>
void test2(T f)
{
	f(7);
	auto g = f;
	g(8);
}

int main(int argc, char *argv[])
{

Scheduler *s;
s = Scheduler::getInstance();
boost::this_thread::sleep(boost::posix_time::seconds(1));
s->finish();
s->join();

Scheduler *p;
p = new Scheduler(*s);

string z = "ala ma kota";
cout << z << endl;

auto w = boost::bind(test, _1);

Logger l;
boost::function<void (void)> ff;
ff = boost::bind(&Logger::write, &l, "zxcxzcqwee");
//ff();
Request req;
req.load(ff);
req.call();



system("PAUSE");
return 0;
}


void runScheduler()
{
	Scheduler *s;
	s = Scheduler::getInstance();
	boost::this_thread::sleep(boost::posix_time::seconds(3));
	s->finish();
	s->join();
}