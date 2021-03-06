//	DDCPP/standard/bits/DD_ReadOnlyCall.hpp
#ifndef DD_READ_ONLY_CALL_HPP_INCLUDED_
#	define DD_READ_ONLY_CALL_HPP_INCLUDED_ 1



#	include "DD_Conditional.hpp"
#	include "DD_IsTriviallyCopyConstructible.hpp"
#	include "DD_RemoveReference.hpp"
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ArgumentT_>
struct ReadOnlyCall_ {
#	if __cplusplus >= 201103L
	using Type = ConditionalType<
		IsTriviallyCopyConstructible<ArgumentT_>::value && sizeof(ArgumentT_) <= sizeof(void*),
		ArgumentT_,
		ArgumentT_ const&
	>;
#	else
	typedef typename Conditional<
		IsTriviallyCopyConstructible<ArgumentT_>::value && sizeof(ArgumentT_) <= sizeof(void*),
		ArgumentT_,
		ArgumentT_ const&
	>::Type Type;
#	endif


};



template <typename ArgumentT_>
struct ReadOnlyCall : ReadOnlyCall_<DD_MODIFY_TRAIT(RemoveCV, DD_MODIFY_TRAIT(RemoveReference, ArgumentT_))> {
};



DD_TRAIT_MODIFIER(ReadOnlyCall)



DD_DETAIL_END_



DD_BEGIN_
using detail_::ReadOnlyCall;
DD_TRAIT_MODIFIER(ReadOnlyCall)



DD_END_



#endif
