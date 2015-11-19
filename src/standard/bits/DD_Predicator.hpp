//	DDCPP/standard/bits/DD_Predicator.hpp
#ifndef DD_PREDICATOR_HPP_INCLUDED_
#	define DD_PREDICATOR_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::Predicator'.



#	endif
#	include "DD_Function.hpp"



DD_DETAIL_BEGIN_
template <typename FunctionT_>
struct Predicator;



template <typename ResultT_, typename... ArgumentsT_>
struct Predicator<ResultT_(ArgumentsT_...)> : Function<ResultT_(ArgumentsT_...)> {
	using SuperType = Function<ResultT_(ArgumentsT_...)>;
	using ThisType = Predicator<ResultT_(ArgumentsT_...)>;


	constexpr Predicator() = default;

	constexpr Predicator(ThisType const& origin_) = default;

	constexpr Predicator(ThisType&& origin_) = default;

	constexpr Predicator(SuperType function_) : SuperType(move(function_)) {
	}


	ThisType& operator =(ThisType const& origin_) = default;

	ThisType& operator =(ThisType&& origin_) = default;


};



template <typename ResultT_, typename... ArgumentsT_>
inline Predicator<ResultT_(ArgumentsT_...)> constexpr make_predicator(PointerType<ResultT_(ArgumentsT_...)> function_) noexcept(
	noexcept(Predicator<ResultT_(ArgumentsT_...)>(function_))
) {
	return Predicator<ResultT_(ArgumentsT_...)>(function_);
}


template <typename ResultT_, typename... ArgumentsT_>
inline Predicator<ResultT_(ArgumentsT_...)> constexpr logic_and(
	Predicator<ResultT_(ArgumentsT_...)> predicator_1_,
	Predicator<ResultT_(ArgumentsT_...)> predicator_2_
) {
	return Predicator<ResultT_(ArgumentsT_...)>([predicator_1_, predicator_2_](ArgumentsT_... arguments__) {
		return predicator_1_(arguments__...) && predicator_2_(arguments__...);
	});
}


template <typename ResultT_, typename... ArgumentsT_>
inline Predicator<ResultT_(ArgumentsT_...)> constexpr logic_or(
	Predicator<ResultT_(ArgumentsT_...)> predicator_1_,
	Predicator<ResultT_(ArgumentsT_...)> predicator_2_
) {
	return Predicator<ResultT_(ArgumentsT_...)>([predicator_1_, predicator_2_](ArgumentsT_... arguments__) {
		return predicator_1_(arguments__...) || predicator_2_(arguments__...);
	});
}



template <typename ResultT_, typename... ArgumentsT_>
inline Predicator<ResultT_(ArgumentsT_...)> constexpr operator &&(
	Predicator<ResultT_(ArgumentsT_...)> predicator_1_,
	Predicator<ResultT_(ArgumentsT_...)> predicator_2_
) {
	return logic_and(predicator_1_, predicator_2_);
}


template <typename ResultT_, typename... ArgumentsT_>
inline Predicator<ResultT_(ArgumentsT_...)> constexpr operator ||(
	Predicator<ResultT_(ArgumentsT_...)> predicator_1_,
	Predicator<ResultT_(ArgumentsT_...)> predicator_2_
) {
	return logic_or(predicator_1_, predicator_2_);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::Predicator;

using detail_::make_predicator;



DD_END_



#endif
