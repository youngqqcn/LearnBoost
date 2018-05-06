#if 0
// example5.cpp
#define BOOST_TEST_MODULE mytest
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(mytest)

BOOST_AUTO_TEST_CASE(test1) {
	BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(test2) {
	typedef enum { red = 8, blue, green = 1, yellow, black } color;
	color c = green;
	BOOST_WARN(sizeof(green) > sizeof(char));
	BOOST_CHECK(c == 2); // BOOST_CHECK∂œ—‘ ß∞‹ºÃ–¯÷¥––
	BOOST_REQUIRE(yellow > red); //BOOST_REQUIRE∂œ—‘ ß∞‹£¨≤‚ ‘Õ£÷π
	BOOST_CHECK(black != 4);

	//while (1) {};
	//std::cin.get();
}

BOOST_AUTO_TEST_SUITE_END()




#endif 
