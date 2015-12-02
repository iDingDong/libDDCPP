//	DDCPP/standard/bits/DD_IteratorTrait.hpp
#ifndef DD_ITERATOR_TRAIT_HPP_INCLUDED_
#	define DD_ITERATOR_TRAIT_HPP_INCLUDED_ 1



#	include "DD_Trait.hpp"
#	include "DD_IteratorReverse.hpp"
#	include "DD_IsUndirectionalIterator.hpp"
#	include "DD_IsBidirectionalIterator.hpp"
#	include "DD_IsFreeAccessIterator.hpp"
#	include "DD_Iterator.hpp"
#	include "DD_ConstIterator.hpp"
#	include "DD_ReverseIterator.hpp"
#	include "DD_ConstReverseIterator.hpp"
#	include "DD_IteratorValue.hpp"
#	include "DD_IteratorReference.hpp"
#	include "DD_IteratorPointer.hpp"
#	include "DD_IteratorDifference.hpp"



DD_BEGIN_
template <typename IteratorT_>
struct IteratorTrait : Trait<IteratorT_> {
	DD_ALIAS(IteratorType, IteratorT_);

	DD_ALIAS(IsUndiretionalIterator, DD::IsUndirectionalIterator<IteratorType>);
	DD_ALIAS(IsBidiretionalIterator, DD::IsBidirectionalIterator<IteratorType>);
	DD_ALIAS(IsFreeAccessIterator, DD::IsFreeAccessIterator<IteratorType>);

	DD_ALIAS(ValueType, DD_MODIFY_TRAIT(IteratorValue, IteratorType));
	DD_ALIAS(ReferenceType, DD_MODIFY_TRAIT(IteratorReference, IteratorType));
	DD_ALIAS(PointerType, DD_MODIFY_TRAIT(IteratorPointer, IteratorType));
	DD_ALIAS(DifferenceType, DD_MODIFY_TRAIT(IteratorDifference, IteratorType));
	DD_ALIAS(CatagoryType, DD_MODIFY_TRAIT(IteratorCatagory, IteratorType));
	DD_ALIAS(ReverseType, DD_MODIFY_TRAIT(IteratorReverse, IteratorType));


};



DD_END_



#endif
