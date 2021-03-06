//	DDCPP/standard/bits/DD_build_heap.hpp
#ifndef DD_BUILD_HEAP_HPP_INCLUDED_
#	define DD_BUILD_HEAP_HPP_INCLUDED_ 1



#	include "DD_heapify.hpp"



DD_DETAIL_BEGIN_
template <typename FreeAccessIteratorT_, typename BinaryPredicateT_>
inline ProcessType build_heap(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__,
	BinaryPredicateT_ less__
) {
	for (FreeAccessIteratorT_ current__(::DD::middle(begin__, end__ - 1)); current__ >= begin__; --current__) {
		::DD::heapify(begin__, end__, current__, less__);
	}
}

template <typename FreeAccessIteratorT_>
inline ProcessType build_heap(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__
) DD_NOEXCEPT_AS(::DD::detail_::build_heap(begin__ DD_COMMA end__ DD_COMMA less_than)) {
	::DD::detail_::build_heap(begin__, end__, less_than);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::build_heap;



DD_END_



#endif
