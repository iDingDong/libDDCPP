//	DDCPP/standard/bits/DD_count.hpp
#ifndef DD_COUNT_HPP_INCLUDED_
#	define DD_COUNT_HPP_INCLUDED_ 1



#	include "DD_Iterator.hpp"
#	include "DD_IteratorDifference.hpp"
#	include "DD_Range.hpp"
#	include "DD_EqualTo.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename ValueT_, typename BinaryPredicateT_>
DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_) count(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	ValueT_ value__,
	BinaryPredicateT_ equal__
) DD_NOEXCEPT_AS(++begin__ != end__ && equal__(*begin__, value__)) {
#	if __cplusplus >= 201103L
	auto result_ = DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_)();
#	else
	typedef DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_) ResultType_;
	ResultType_ result_ = ResultType_();
#	endif
	for (; begin__ != end__; ++begin__) {
		if (equal__(*begin__, value__)) {
			++result_;
		}
	}
	return result_;
}

template <typename UndirectionalIteratorT_, typename ValueT_>
inline DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_) count(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	ValueT_ value__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_)>(
	::DD::detail_::count(begin__ DD_COMMA end__ DD_COMMA value__ DD_COMMA equal_to)
)) {
	return ::DD::detail_::count(begin__, end__, value__, equal_to);
}

template <typename UndirectionalRangeT_, typename ValueT_, typename BinaryPredicateT_>
inline DD_MODIFY_TRAIT(IteratorDifference, DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)) count(
	UndirectionalRangeT_& range__,
	ValueT_ const& value__,
	BinaryPredicateT_ equal__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(IteratorDifference, DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_))>(
	::DD::detail_::count(DD_SPLIT_RANGE(range__) DD_COMMA value__ DD_COMMA equal__)
)) {
	return ::DD::detail_::count(DD_SPLIT_RANGE(range__), value__, equal__);
}

template <typename UndirectionalRangeT_, typename ValueT_>
inline DD_MODIFY_TRAIT(IteratorDifference, DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)) count(
	UndirectionalRangeT_& range__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(IteratorDifference, DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_))>(
	::DD::detail_::count(range__ DD_COMMA value__ DD_COMMA equal_to)
)) {
	return ::DD::detail_::count(range__, value__, equal_to);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::count;



DD_END_



#endif
