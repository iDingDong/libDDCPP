//	DDCPP/standard/bits/DD_get_length.hpp
#ifndef DD_GET_LENGTH_HPP_INCLUDED_
#	define DD_GET_LENGTH_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_, LengthType length_c_>
#	if __cplusplus >= 201103L
inline LengthType constexpr get_length(ArrayType<ValueT_, length_c_> const& array_) noexcept {
#	else
inline LengthType get_length(ValueT_(&array_)[length_c_] array_) throw() {
#	endif
	return length_c_;
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::get_length;



DD_END_



#endif
