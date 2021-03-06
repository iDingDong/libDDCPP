#ifndef TEST_ALGORITHM_H_INCLUDED_
#	define TEST_ALGORITHM_H_INCLUDED_ 1



#	define DDCPP_DEBUG DD_ON



#	include "standard/DDIterator.hpp"
#	include "standard/DDUtility.hpp"
#	include "standard/DDHub.hpp"



template <typename ContainerT>
inline void print_container(ContainerT const& container) {
	for (auto it(DD::begin(container)); it != DD::end(container); ++it) {
		DD_PRINT *it, ", ";
	}
	DD_PRINT DD::end_line;
}


void test_algorithm();



#endif
