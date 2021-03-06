//	DDCPP/standard/bits/DD_is_sorted_until.hpp
#ifndef DD_IS_SORTED_UNTIL_HPP_INCLUDED_
#	define DD_IS_SORTED_UNTIL_HPP_INCLUDED_ 1



#	include "DD_IsFreeAccessIterator.hpp"
#	include "DD_Iterator.hpp"
#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_free_access_iterator_>
struct IsSortedUntil_ {
	template <typename UndirectionalIteratorT__>
	static UndirectionalIteratorT__ is_sorted_until_(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___
	) DD_NOEXCEPT_AS(++begin___ != end___ && *begin___ < *begin___ DD_COMMA UndirectionalIteratorT__(begin___)) {
		if (begin___ != end___) {
			for (UndirectionalIteratorT__ front___(begin___); ++begin___ != end___ && !(*begin___ < *front___); ) {
				front___ = begin___;
			}
		}
		return begin___;
	}

	template <typename UndirectionalIteratorT__, typename BinaryPredicateT__>
	static UndirectionalIteratorT__ is_sorted_until_(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___,
		BinaryPredicateT__ less___
	) DD_NOEXCEPT_AS(++begin___ != end___ && less___(*begin___ DD_COMMA *begin___) DD_COMMA UndirectionalIteratorT__(begin___)) {
		if (begin___ != end___) {
			for (UndirectionalIteratorT__ front___(begin___); ++begin___ != end___ && !less___(*begin___, *front___); ) {
				front___ = begin___;
			}
		}
		return begin___;
	}


};



template <>
struct IsSortedUntil_<true> {
	template <typename FreeAccessIteratorT__>
	static FreeAccessIteratorT__ is_sorted_until_(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ end___
	) DD_NOEXCEPT_AS(++begin___ < end___ && *begin___ < *(begin___ - 1)) {
		if (begin___ < end___) {
			do {
				++begin___;
			} while (begin___ < end___ && !(*begin___ < *(begin___ - 1)));
		}
		return begin___;
	}

	template <typename FreeAccessIteratorT__, typename BinaryPredicateT__>
	static FreeAccessIteratorT__ is_sorted_until_(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ end___,
		BinaryPredicateT__ less___
	) DD_NOEXCEPT_AS(++begin___ < end___ && less___(*begin___ DD_COMMA *(begin___ - 1))) {
		if (begin___ < end___) {
			do {
				++begin___;
			} while (begin___ < end___ && !less___(*begin___, *(begin___ - 1)));
		}
		return begin___;
	}


};



template <typename UndirectionalIteratorT_>
inline UndirectionalIteratorT_ is_sorted_until(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__
) DD_NOEXCEPT_AS(IsSortedUntil_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::is_sorted_until_(begin__ DD_COMMA end__)) {
	return IsSortedUntil_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::is_sorted_until_(begin__, end__);
}

template <typename UndirectionalIteratorT_, typename BinaryPredicateT_>
inline UndirectionalIteratorT_ is_sorted_until(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(IsSortedUntil_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::is_sorted_until_(begin__ DD_COMMA end__ DD_COMMA less__)) {
	return IsSortedUntil_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::is_sorted_until_(begin__, end__, less__);
}

template <typename UndirectionalRangeT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) is_sorted_until(
	UndirectionalRangeT_& range__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>(
	::DD::detail_::is_sorted_until(DD_SPLIT_RANGE(range__))
)) {
	return ::DD::detail_::is_sorted_until(DD_SPLIT_RANGE(range__));
}

template <typename UndirectionalRangeT_, typename BinaryPredicateT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) is_sorted_until(
	UndirectionalRangeT_& range__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>(
	::DD::detail_::is_sorted_until(DD_SPLIT_RANGE(range__) DD_COMMA less__)
)) {
	return ::DD::detail_::is_sorted_until(DD_SPLIT_RANGE(range__), less__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::is_sorted_until;



DD_END_



#endif
