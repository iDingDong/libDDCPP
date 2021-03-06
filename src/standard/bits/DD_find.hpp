//	DDCPP/standard/bits/DD_find.hpp
#ifndef DD_FIND_HPP_INCLUDED_
#	define DD_FIND_HPP_INCLUDED_ 1



#	include "DD_Iterator.hpp"
#	include "DD_Range.hpp"
#	include "DD_EqualTo.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename ValueT_, typename BinaryPredicateT_>
UndirectionalIteratorT_ find(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	ValueT_ const& value__,
	BinaryPredicateT_ equal__
) DD_NOEXCEPT_AS(begin__ != end__ && equal__(*++begin__, value__)) {
	while (begin__ != end__ && !equal__(*begin__, value__)) {
		++begin__;
	}
	return begin__;
}

template <typename UndirectionalIteratorT_, typename ValueT_>
inline UndirectionalIteratorT_ find(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(static_cast<UndirectionalIteratorT_>(
	::DD::detail_::find(begin__ DD_COMMA end__ DD_COMMA value__ DD_COMMA equal_to)
)) {
	return ::DD::detail_::find(begin__, end__, value__, equal_to);
}

template <typename UndirectionalRangeT_, typename ValueT_, typename BinaryPredicateT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find(
	UndirectionalRangeT_& range__,
	ValueT_ const& value__,
	BinaryPredicateT_ equal__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>(
	::DD::detail_::find(DD_SPLIT_RANGE(range__) DD_COMMA value__ DD_COMMA equal__)
)) {
	return ::DD::detail_::find(DD_SPLIT_RANGE(range__), value__, equal__);
}

template <typename UndirectionalRangeT_, typename ValueT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find(
	UndirectionalRangeT_& range__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>(
	::DD::detail_::find(range__ DD_COMMA value__ DD_COMMA equal_to)
)) {
	return ::DD::detail_::find(range__, value__, equal_to);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::find;



DD_END_



#endif
