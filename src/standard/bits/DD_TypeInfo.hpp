//	DDCPP/standard/bits/DD_TypeInfo.hpp
#ifndef DD_TYPE_INFO_HPP_INCLUDED_
#	define DD_TYPE_INFO_HPP_INCLUDED_ 1



#	include <typeinfo>

#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
DD_ALIAS(TypeInfo, std::type_info);



DD_DETAIL_END_



DD_BEGIN_
using detail_::TypeInfo;



DD_END_



#endif
