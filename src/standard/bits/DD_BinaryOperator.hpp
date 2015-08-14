//	DDCPP/standard/bits/DD_BinaryOperator.hpp
#if _DD_BINARY_OPERATOR_HPP_INCLUDED
#	define _DD_BINARY_OPERATOR_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



#	define DD_BINARY_OPERATOR(_ARG_Operator, _ARG_target)\
	template <typename _MACRO_ObjectT1, typename _MACRO_ObjectT2 = _MACRO_ObjectT1>\
	struct _ARG_Operator {\
		DD_ALIAS(Type1, _MACRO_ObjectT1)\
		DD_ALIAS(Type2, _MACRO_ObjectT2)\
		\
		\
		friend Type1 operator _ARG_target(Type1 const& _object_1, Type2 const& _object_2) DD_NOEXCEPT_AS() {\
			Type1 _temp(_object_1);\
			_temp _ARG_target##= _object_2;\
			return _temp;\
		}\
		\
		\
	};



DD_BEGIN
DD_BINARY_OPERATOR(Addable, +)
DD_BINARY_OPERATOR(Subtractable, -)
DD_BINARY_OPERATOR(Multipliable, *)
DD_BINARY_OPERATOR(Dividable, /)
DD_BINARY_OPERATOR(Modable, %)



DD_END



#	undef DD_BINARY_OPERATOR



#endif
