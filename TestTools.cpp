#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;
using namespace boost::unit_test_framework;

BOOST_AUTO_TEST_CASE( SimpleTestTools ) {
    int a = 2;
	BOOST_CHECK(1 == 2);
    //BOOST_WARN( sizeof(int) < sizeof(long) );
   // BOOST_CHECK( a == 1 );
    //BOOST_REQUIRE( a > 3 );
    //BOOST_CHECK( a == 2 );
	system("PAUSE");
}
