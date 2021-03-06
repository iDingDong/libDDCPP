//	DDCPP/standard/bits/DD_length_difference.hpp
#ifndef DD_LENGTH_DIFFERENCE_HPP_INCLUDED_
#	define DD_LENGTH_DIFFERENCE_HPP_INCLUDED_ 1



#	include "DD_IsFreeAccessIterator.hpp"
#	include "DD_IteratorDifference.hpp"
#	include "DD_Iterator.hpp"
#	include "DD_next.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_free_access_iterator_>
struct LengthDifference_ {
	template <typename UndirectionalIteratorT__>
	static DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT__) length_difference(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___
	) DD_NOEXCEPT_AS(++begin___ != end___) {
#	if __cplusplus < 201103L || __cplusplus >= 201402L
#		if __cplusplus >= 201402L
		auto result_ = IteratorDifferenceType<UndirectionalIteratorT__>();
#		else
		typedef typename IteratorDifference<UndirectionalIteratorT__>::Type ResultType_;
		ResultType_ result_ = ResultType_();
#		endif
		for (; begin___ != end___; ++begin___) {
			++result_;
		}
		return result_;
#	else
		return begin___ == end___ ? 0 : length_difference(::DD::next(begin___), end___) + 1;
#	endif
	}


};



template <>
struct LengthDifference_<true> {
	template <typename FreeAccessIteratorT__>
	static DD_MODIFY_TRAIT(IteratorDifference, FreeAccessIteratorT__) length_difference(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ end___
	) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(IteratorDifference, FreeAccessIteratorT__)>(end___ - begin___)) {
		return end___ - begin___;
	}


};



template <typename UndirectionalIteratorT_>
inline DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_) length_difference(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(IteratorDifference, UndirectionalIteratorT_)>(
	LengthDifference_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::length_difference(begin__, end__)
)) {
	return LengthDifference_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::length_difference(begin__, end__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::length_difference;



DD_END_



#endif
