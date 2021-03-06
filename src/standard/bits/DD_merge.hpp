//	DDCPP/standard/bits/DD_merge.hpp
#ifndef DD_MERGE_HPP_INCLUDED_
#	define DD_MERGE_HPP_INCLUDED_ 1



#	include "DD_Iterator.hpp"
#	include "DD_Range.hpp"
#	include "DD_copy.hpp"
#	include "DD_LessThan.hpp"



DD_DETAIL_BEGIN_
template <
	typename UndirectionalIteratorT1_,
	typename UndirectionalIteratorT2_,
	typename BinaryPredicateT_,
	typename UndirectionalIteratorT3_
>
UndirectionalIteratorT3_ merge(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ end_1__,
	UndirectionalIteratorT2_ begin_2__,
	UndirectionalIteratorT2_ end_2__,
	BinaryPredicateT_ less__,
	UndirectionalIteratorT3_ result_begin__
) DD_NOEXCEPT_AS(
	::DD::copy(begin_1__, end_1__, result_begin__) DD_COMMA
	::DD::copy(begin_2__, end_2__, result_begin__) DD_COMMA
	less__(*begin_1__, *begin_2__)
) {
	for (; begin_2__ != end_2__; ++result_begin__) {
		if (begin_1__ == end_1__) {
			return ::DD::copy(begin_2__, end_2__, result_begin__);
		}
		if (less__(*begin_1__, *begin_2__)) {
			*result_begin__ = *begin_1__;
			++begin_1__;
		} else {
			*result_begin__ = *begin_2__;
			++begin_1__;
		}
	}
	return ::DD::copy(begin_1__, end_1__, result_begin__);
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename UndirectionalIteratorT3_>
inline UndirectionalIteratorT3_ merge(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ end_1__,
	UndirectionalIteratorT2_ begin_2__,
	UndirectionalIteratorT2_ end_2__,
	UndirectionalIteratorT3_ result_begin__
) DD_NOEXCEPT_AS(static_cast<UndirectionalIteratorT3_>(::DD::detail_::merge(
	begin_1__ DD_COMMA end_1__ DD_COMMA begin_2__ DD_COMMA end_2__ DD_COMMA less_than DD_COMMA result_begin__
))) {
	return ::DD::detail_::merge(begin_1__, end_1__, begin_2__, end_2__, less_than, result_begin__);
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename BinaryPredicateT_, typename UndirectionalIteratorT3_>
UndirectionalIteratorT3_ merge(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ end_1__,
	UndirectionalIteratorT2_ begin_2__,
	UndirectionalIteratorT2_ end_2__,
	BinaryPredicateT_ less__,
	UndirectionalIteratorT3_ result_begin__,
	UndirectionalIteratorT3_ result_end__
) DD_NOEXCEPT_AS(
	::DD::copy(begin_1__ DD_COMMA end_1__ DD_COMMA result_begin__) DD_COMMA
	::DD::copy(begin_2__ DD_COMMA end_2__ DD_COMMA result_begin__) DD_COMMA
	less__(*begin_1__ DD_COMMA *begin_2__)
) {
	for (; begin_2__ != end_2__; ++result_begin__) {
		if (begin_1__ == end_1__) {
			return ::DD::copy(begin_2__, end_2__, result_begin__, result_end__);
		}
		if (result_begin__ == result_end__) {
			return result_begin__;
		}
		if (less__(*begin_1__, *begin_2__)) {
			*result_begin__ = *begin_1__;
			++begin_1__;
		} else {
			*result_begin__ = *begin_2__;
			++begin_2__;
		}
	}
	return ::DD::copy(begin_1__, end_1__, result_begin__, result_end__);
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename UndirectionalIteratorT3_>
inline UndirectionalIteratorT3_ merge(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ end_1__,
	UndirectionalIteratorT2_ begin_2__,
	UndirectionalIteratorT2_ end_2__,
	UndirectionalIteratorT3_ result_begin__,
	UndirectionalIteratorT3_ result_end__
) DD_NOEXCEPT_AS(static_cast<UndirectionalIteratorT3_>(::DD::detail_::merge(
	begin_1__ DD_COMMA end_1__ DD_COMMA begin_2__ DD_COMMA end_2__ DD_COMMA less_than DD_COMMA result_begin__ DD_COMMA result_end__
))) {
	return ::DD::detail_::merge(begin_1__, end_1__, begin_2__, end_2__, less_than, result_begin__, result_end__);
}

template <
	typename UndirectionalRangeT1_, typename UndirectionalRangeT2_, typename BinaryPredicateT_, typename UndirectionalRangeT3_
>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT3_) merge(
	UndirectionalRangeT1_& range_1__,
	UndirectionalRangeT2_& range_2__,
	BinaryPredicateT_ less__,
	UndirectionalRangeT3_& result_range__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT3_)>(::DD::detail_::merge(
	DD_SPLIT_RANGE(range_1__) DD_COMMA DD_SPLIT_RANGE(range_2__) DD_COMMA less__ DD_COMMA DD_SPLIT_RANGE(result_range__)
))) {
	return ::DD::detail_::merge(DD_SPLIT_RANGE(range_1__), DD_SPLIT_RANGE(range_2__), less__, DD_SPLIT_RANGE(result_range__));
}

template <typename UndirectionalRangeT1_, typename UndirectionalRangeT2_, typename UndirectionalRangeT3_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT3_) merge(
	UndirectionalRangeT1_& range_1__,
	UndirectionalRangeT2_& range_2__,
	UndirectionalRangeT3_& result_range__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT3_)>(
	::DD::detail_::merge(range_1__ DD_COMMA range_2__ DD_COMMA less_than DD_COMMA result_range__)
)) {
	return ::DD::detail_::merge(range_1__, range_2__, less_than, result_range__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::merge;



DD_END_



#endif
