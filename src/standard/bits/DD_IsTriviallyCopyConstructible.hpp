//	DDCPP/standard/bits/DD_IsTriviallyCopyConstructible.hpp
#ifndef _DD_IS_TRIVIALLY_COPY_CONSTRUCTIBLE_HPP_INCLUDED
#	define _DD_IS_TRIVIALLY_COPY_CONSTRUCTIBLE_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#		include "DD_And.hpp"
#	else
#		include "DD_IsArithmetic.hpp"
#	endif



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsTriviallyCopyConstructible : AndType<IsTriviallyCopyConstructible<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsTriviallyCopyConstructible<ObjectT_> : StdBoolConstant<std::is_trivially_copy_constructible<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct IsTriviallyCopyConstructible : IsArithmetic<ObjectT_> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsTriviallyCopyConstructible;



DD_END_



#endif
