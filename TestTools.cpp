#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "Queue.h"
#include "Request.h"

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



BOOST_AUTO_TEST_CASE( fakeStop )
{
	system("PAUSE");
}