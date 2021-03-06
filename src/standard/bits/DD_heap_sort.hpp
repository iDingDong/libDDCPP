//	DDCPP/standard/bits/DD_heap_sort.hpp
#ifndef DD_HEAP_SORT_HPP_INCLUDED_
#	define DD_HEAP_SORT_HPP_INCLUDED_ 1



#	include "DD_build_heap.hpp"



DD_DETAIL_BEGIN_
template <typename FreeAccessIteratorT_, typename BinaryPredicateT_>
inline ProcessType heap_sort(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__,
	BinaryPredicateT_ less__
) {
	::DD::build_heap(begin__, end__, less__);
	while (begin__ < --end__) {
		::DD::swap_target(begin__, end__);
		::DD::heapify(begin__, end__, begin__, less__);
	}
}

template <typename FreeAccessIteratorT_>
inline ProcessType heap_sort(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__
) DD_NOEXCEPT_AS(::DD::detail_::heap_sort(begin__ DD_COMMA end__ DD_COMMA less_than)) {
	::DD::detail_::heap_sort(begin__, end__, less_than);
}

template <typename FreeAccessRangeT_, typename BinaryPredicateT_>
inline ProcessType heap_sort(
	FreeAccessRangeT_& range__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(::DD::detail_::heap_sort(DD_SPLIT_RANGE(range__) DD_COMMA less__)) {
	::DD::detail_::heap_sort(DD_SPLIT_RANGE(range__), less__);
}

template <typename FreeAccessRangeT_>
inline ProcessType heap_sort(
	FreeAccessRangeT_& range__
) DD_NOEXCEPT_AS(::DD::detail_::heap_sort(range__ DD_COMMA less_than)) {
	::DD::detail_::heap_sort(range__, less_than);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::heap_sort;



DD_END_



#endif
