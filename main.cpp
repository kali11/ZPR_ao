#include <iostream>
#include <boost/regex.hpp>
#include <iterator>
#include <algorithm>
#include "Queue.h"
#include "Scheduler.h"
#include "Logproxy.h"

using namespace std;

Scheduler *s;

int main(int argc, char *argv[])
{

//Scheduler *s;
//s = Scheduler::getInstance();


//Scheduler *p;
//p = new Scheduler(*s);

string z = "ala ma kota";
cout << z << endl;

//auto w = boost::bind(test, _1);

/*
Logger l;
boost::function<void (void)> ff;
ff = boost::bind(&Logger::write, &l, "zxcxzcqwee");
//ff();
Request req;
req.load(ff);
req.call();
*/

Logproxy proxy;
proxy.write("Piotr Kaliniowski");
proxy.write("Piotr Kaliniowski");
s = Scheduler::getInstance();
boost::thread thrd(ref(*s));

boost::this_thread::sleep(boost::posix_time::milliseconds(500));

s->finish();
thrd.join();
//s->join();

system("PAUSE");

delete s;
return 0;
}