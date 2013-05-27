#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "Queue.h"
#include "Request.h"
#include "Logger.h"
#include "Scheduler.h"
#include "Logproxy.h"
#include <boost\thread.hpp>

using namespace boost::unit_test;
using namespace boost::unit_test_framework;

BOOST_AUTO_TEST_CASE( SimpleTest )
{
	int a = 2;
	BOOST_CHECK(a == 2);
}

// test klasy Queue
BOOST_AUTO_TEST_CASE( queueClass )
{
	Request * req;
	Queue * q = new Queue();
	req = q->get();
	BOOST_CHECK(req == NULL);
	Request *req2 = new Request();
	q->add(req2);
	req = q->get();
	BOOST_CHECK(req == req2);
}

//test klasy Logger
Logger l;
void reader()
{
	for(;;)
	{
		
		l.read();
		boost::this_thread::interruption_point();
		
	}
}
void writer()
{
	l.write("");
	//boost::this_thread::interruption_point();
}
BOOST_AUTO_TEST_CASE(LoggerClass)
{
	
	boost::thread thrd1(&reader);
	boost::thread thrd3(&writer);
	boost::thread thrd2(&reader);
	
	boost::this_thread::sleep(boost::posix_time::milliseconds(200));
	cout << "konec" << endl;
	thrd1.interrupt();
	thrd2.interrupt();
	cout << "konec222" << endl;
	thrd3.interrupt();
	thrd2.join();
	cout << "qfghh" << endl;
	thrd1.join();
	thrd3.join();

}



BOOST_AUTO_TEST_CASE( fakeStop )
{
	system("PAUSE");
}

BOOST_AUTO_TEST_CASE( Scheduler_test )
{
	Scheduler *s = Scheduler::getInstance(4);
	Logproxy lp;
	for(int i = 0; i < 10; ++i)
	{
		lp.write("");
	}
	boost::thread thread(&Scheduler::operator(), s);
	boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
	s->finish();
}

BOOST_AUTO_TEST_CASE( fakeStop2 )
{
	system("PAUSE");
}