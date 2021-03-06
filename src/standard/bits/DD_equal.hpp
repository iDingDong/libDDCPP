//	DDCPP/standard/bits/DD_equal.hpp
#ifndef DD_EQUAL_HPP_INCLUDED_
#	define DD_EQUAL_HPP_INCLUDED_ 1



#	include <cstring>

#	if __cplusplus >= 201103L
#		include "DD_IsScalar.hpp"
#	else
#		include "DD_IsArithmetic.hpp"
#	endif
#	include "DD_IsPointer.hpp"
#	include "DD_IsSame.hpp"
#	include "DD_IsOriginalImplementation.hpp"
#	include "DD_IsRange.hpp"
#	include "DD_IteratorValue.hpp"
#	include "DD_EqualTo.hpp"
#	include "DD_length_difference.hpp"
#	include "DD_size_distance.hpp"
#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_trivially_equal_predicatable_c_>
struct Equal_ {
	template <ValidityType is_free_access_iterator_c__, int workaround_c__ = 0>
	struct Equal__ {
		template <typename UndirectionalIteratorT1___, typename UndirectionalIteratorT2___, typename BinaryPredicateT___>
		static ValidityType equal(
			UndirectionalIteratorT1___ begin_1____,
			UndirectionalIteratorT1___ end_1____,
			UndirectionalIteratorT2___ begin_2____,
			UndirectionalIteratorT2___ end_2____,
			BinaryPredicateT___ equal____
		) DD_NOEXCEPT_AS(++begin_1____ != end_1____ && ++begin_2____ == end_2____ && equal____(*begin_1____, *begin_2____)) {
			for (; begin_1____ != end_1____; ++begin_1____, ++begin_2____) {
				if (begin_2____ == end_2____) {
					return false;
				} else if (!equal____(*begin_1____, *begin_2____)) {
					return false;
				}
			}
			return begin_2____ == end_2____;
		}


	};


	template <int workaround_c__>
	struct Equal__<true, workaround_c__> {
		template <typename FreeAccessIteratorT1___, typename FreeAccessIteratorT2___, typename BinaryPredicateT___>
		static ValidityType equal(
			FreeAccessIteratorT1___ begin_1____,
			FreeAccessIteratorT1___ end_1____,
			FreeAccessIteratorT2___ begin_2____,
			FreeAccessIteratorT2___ end_2____,
			BinaryPredicateT___ equal____
		) DD_NOEXCEPT_AS(
			equal____(
				*(begin_1____ + length_difference(begin_1____ DD_COMMA end_1____)) DD_COMMA
				*(begin_2____ + length_difference(begin_2____ DD_COMMA end_2____))
			)
		) {
#	if __cplusplus >= 201103L
			auto length_ = length_difference(begin_1____, end_1____);
#	else
			typename IteratorDifference<FreeAccessIteratorT1__>::Type length_ = length_difference(begin_1____, end_1____);
#	endif
			if (length_ != length_difference(begin_2____, end_2____)) {
				return false;
			}
			while (length_--) {
				if (!equal____(*(begin_1____ + length_), *(begin_2____ + length_))) {
					return false;
				}
			}
			return true;
		}


	};


	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__, typename BinaryPredicateT__>
	static ValidityType equal(
		UndirectionalIteratorT1__ begin_1___,
		UndirectionalIteratorT1__ end_1___,
		UndirectionalIteratorT2__ begin_2___,
		BinaryPredicateT__ equal___
	) DD_NOEXCEPT_AS(begin_1___ != end_1___ && equal___(*++begin_1___ DD_COMMA *++begin_2___)) {
		for (; begin_1___ != end_1___; ++begin_1___, ++begin_2___) {
			if (!equal___(*begin_1___, *begin_2___)) {
				return false;
			}
		}
		return true;
	}

	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__, typename BinaryPredicateT__>
	static ValidityType equal(
		UndirectionalIteratorT1__ begin_1___,
		UndirectionalIteratorT1__ end_1___,
		UndirectionalIteratorT2__ begin_2___,
		UndirectionalIteratorT2__ end_2___,
		BinaryPredicateT__ equal___
	) DD_NOEXCEPT_AS(
		Equal__<
			IsFreeAccessIterator<UndirectionalIteratorT1__ DD_COMMA UndirectionalIteratorT2__>::value
		>::equal(begin_1___ DD_COMMA end_1___ DD_COMMA begin_2___ DD_COMMA end_2___ DD_COMMA equal___)
	) {
		return Equal__<
#	if __cplusplus >= 201103L
			IsFreeAccessIterator<UndirectionalIteratorT1__, UndirectionalIteratorT2__>::value
#	else
			IsFreeAccessIterator<UndirectionalIteratorT1__>::value && IsFreeAccessIterator<UndirectionalIteratorT2__>::value
#	endif
		>::equal(begin_1___, end_1___, begin_2___, end_2___, equal___);
	}


};



template <>
struct Equal_<true> {
	template <typename PointerT1__, typename PointerT2__, typename BinaryPredicateT__>
	static ValidityType equal(
		PointerT1__ begin_1___,
		PointerT1__ end_1___,
		PointerT2__ begin_2___,
		BinaryPredicateT__ original_equal___
	) DD_NOEXCEPT_AS(static_cast<SizeType>(::DD::size_distance(begin_1___ DD_COMMA end_1___))) {
		return !std::memcmp(get_pointer(begin_1___), get_pointer(begin_2___), size_distance(begin_1___, end_1___));
	}

	template <typename PointerT1__, typename PointerT2__, typename BinaryPredicateT__>
	static ValidityType equal(
		PointerT1__ begin_1___,
		PointerT1__ end_1___,
		PointerT2__ begin_2___,
		PointerT2__ end_2___,
		BinaryPredicateT__ original_equal___
	) DD_NOEXCEPT_AS(static_cast<SizeType>(::DD::size_distance(begin_1___ DD_COMMA end_1___))) {
		SizeType size_ = ::DD::size_distance(begin_1___, end_1___);
		return size_ == size_distance(begin_2___, end_2___) && !std::memcmp(get_pointer(begin_1___), get_pointer(begin_2___), size_);
	}


};



template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename BinaryPredicateT_>
inline ValidityType equal(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ end_1__,
	UndirectionalIteratorT2_ begin_2__,
	BinaryPredicateT_ equal__
) DD_NOEXCEPT_AS(
	Equal_<
		AndType<
			IsScalar<IteratorValueType<UndirectionalIteratorT1_>> DD_COMMA
			IsPointer<UndirectionalIteratorT1_ DD_COMMA UndirectionalIteratorT2_> DD_COMMA
			IsSame<
				RemoveCVType<IteratorValueType<UndirectionalIteratorT1_>> DD_COMMA
				RemoveCVType<IteratorValueType<UndirectionalIteratorT2_>>
			> DD_COMMA
			IsOriginalImplementation<BinaryPredicateT_>
		>::value
	>::equal(begin_1__ DD_COMMA end_1__ DD_COMMA begin_2__ DD_COMMA equal__)
) {
	return Equal_<
#	if __cplusplus >= 201103L
		AndType<
			IsScalar<IteratorValueType<UndirectionalIteratorT1_>>,
			IsPointer<UndirectionalIteratorT1_, UndirectionalIteratorT2_>,
			IsSame<
				RemoveCVType<IteratorValueType<UndirectionalIteratorT1_>>,
				RemoveCVType<IteratorValueType<UndirectionalIteratorT2_>>
			>,
			IsOriginalImplementation<BinaryPredicateT_>
		>::value
#	else
		IsArithmetic<
			typename IteratorValue<UndirectionalIteratorT1_>::Type>::value &&
			IsPointer<UndirectionalIteratorT1_>::value &&
			IsPointer<UndirectionalIteratorT2_>::value &&
			IsSame<
				typename RemoveCV<typename IteratorValue<UndirectionalIteratorT1_>::Type>::Type,
				typename RemoveCV<typename IteratorValue<UndirectionalIteratorT2_>::Type>::Type
			> &&
			IsOriginalImplementation<BinaryPredicateT_>
		>::value
#	endif
	>::equal(begin_1__, end_1__, begin_2__, equal__);
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename BinaryPredicateT_>
inline ValidityType equal(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ end_1__,
	UndirectionalIteratorT2_ begin_2__,
	UndirectionalIteratorT2_ end_2__,
	BinaryPredicateT_ equal__
) DD_NOEXCEPT_AS(
	Equal_<
		AndType<
			IsScalar<IteratorValueType<UndirectionalIteratorT1_>> DD_COMMA
			IsPointer<UndirectionalIteratorT1_ DD_COMMA UndirectionalIteratorT2_> DD_COMMA
			IsSame<
				RemoveCVType<IteratorValueType<UndirectionalIteratorT1_>> DD_COMMA
				RemoveCVType<IteratorValueType<UndirectionalIteratorT2_>>
			> DD_COMMA
			IsOriginalImplementation<BinaryPredicateT_>
		>::value
	>::equal(begin_1__ DD_COMMA end_1__ DD_COMMA begin_2__ DD_COMMA end_2__ DD_COMMA equal__)
) {
	return Equal_<
#	if __cplusplus >= 201103L
		AndType<
			IsScalar<IteratorValueType<UndirectionalIteratorT1_>>,
			IsPointer<UndirectionalIteratorT1_, UndirectionalIteratorT2_>,
			IsSame<
				RemoveCVType<IteratorValueType<UndirectionalIteratorT1_>>,
				RemoveCVType<IteratorValueType<UndirectionalIteratorT2_>>
			>,
			IsOriginalImplementation<BinaryPredicateT_>
		>::value
#	else
		IsArithmetic<
			typename IteratorValue<UndirectionalIteratorT1_>::Type>::value &&
			IsPointer<UndirectionalIteratorT1_>::value &&
			IsPointer<UndirectionalIteratorT2_>::value &&
			IsSame<
				typename RemoveCV<typename IteratorValue<UndirectionalIteratorT1_>::Type>::Type,
				typename RemoveCV<typename IteratorValue<UndirectionalIteratorT2_>::Type>::Type
			> &&
			IsOriginalImplementation<BinaryPredicateT_>
		>::value
#	endif
	>::equal(begin_1__, end_1__, begin_2__, end_2__, equal__);
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
inline ValidityType equal(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ end_1__,
	UndirectionalIteratorT2_ begin_2__,
	UndirectionalIteratorT2_ end_2__
) DD_NOEXCEPT_AS(::DD::detail_::equal(begin_1__ DD_COMMA end_1__ DD_COMMA begin_2__ DD_COMMA end_2__ DD_COMMA equal_to)) {
	return ::DD::detail_::equal(begin_1__, end_1__, begin_2__, end_2__, equal_to);
}



template <ValidityType is_range_c_>
struct EqualResolutionWorkaround_ {
	template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
	static ValidityType equal(
		UndirectionalIteratorT1_ begin_1__,
		UndirectionalIteratorT1_ end_1__,
		UndirectionalIteratorT2_ begin_2__
	) DD_NOEXCEPT_AS(::DD::detail_::equal(begin_1__ DD_COMMA end_1__ DD_COMMA begin_2__ DD_COMMA equal_to)) {
		return ::DD::detail_::equal(begin_1__, end_1__, begin_2__, equal_to);
	}


};



template <>
struct EqualResolutionWorkaround_<true> {
	template <typename UndirectionalRangeT1_, typename UndirectionalRangeT2_, typename BinaryPredicateT_>
	static ValidityType equal(
		UndirectionalRangeT1_ const& range_1__,
		UndirectionalRangeT2_ const& range_2__,
		BinaryPredicateT_ equal__
	) DD_NOEXCEPT_AS(::DD::detail_::equal(DD_SPLIT_RANGE(range_1__) DD_COMMA DD_SPLIT_RANGE(range_2__) DD_COMMA equal__)) {
		return ::DD::detail_::equal(DD_SPLIT_RANGE(range_1__), DD_SPLIT_RANGE(range_2__), equal__);
	}


};



template <typename ArgumentT1_, typename ArgumentT2_, typename ArgumentT3_>
inline ValidityType equal(
	ArgumentT1_ const& argument_1_,
	ArgumentT2_ const& argument_2_,
	ArgumentT3_ const& argument_3_
) DD_NOEXCEPT_AS(
	EqualResolutionWorkaround_<IsRange<ArgumentT1_>::value>::equal(argument_1_ DD_COMMA argument_2_ DD_COMMA argument_3_)
) {
	return EqualResolutionWorkaround_<IsRange<ArgumentT1_>::value>::equal(argument_1_, argument_2_, argument_3_);
}



template <typename UndirectionalRangeT1_, typename UndirectionalRangeT2_>
inline ValidityType equal(
	UndirectionalRangeT1_ const& range_1__,
	UndirectionalRangeT2_ const& range_2__
) DD_NOEXCEPT_AS(::DD::detail_::equal(range_1__ DD_COMMA range_2__ DD_COMMA equal_to)) {
	return ::DD::detail_::equal(range_1__, range_2__, equal_to);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::equal;



DD_END_



#endif
