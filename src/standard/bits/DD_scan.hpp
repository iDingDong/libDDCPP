//	DDCPP/standard/bits/DD_scan.hpp
#ifndef DD_SCAN_HPP_INCLUDED_
#	define DD_SCAN_HPP_INCLUDED_ 1



#	include <iostream>

#	include "DD_Value.hpp"
#	include "DD_fabricate.hpp"



DD_DETAIL_BEGIN_
template <typename BufferT_>
struct GetLineProxy_ {
	DD_ALIAS(ValueType, BufferT_);


	ValueType value_;
	LengthType capacity_;


#	if __cplusplus < 201103L
	GetLineProxy_(
		ValueType& initial_value_,
		LengthType initial_capacity_
	) : value_(initial_value_), capacity_(initial_capacity_) {
	}


#	endif
};



template <typename BufferT_>
struct GetUntilProxy_ {
	DD_ALIAS(ValueType, BufferT_);
	DD_ALIAS(CharType, DD_MODIFY_TRAIT(DD::Value, BufferT_));


	ValueType value_;
	CharType delimiter_;
	LengthType capacity_;


#	if __cplusplus < 201103L
	GetUntilProxy_(
		ValueType& initial_value_,
		CharType initial_delimiter_,
		LengthType initial_capacity_
	) : value_(initial_value_), delimiter_(initial_delimiter_), capacity_(initial_capacity_) {
	}


#	endif
};



template <typename CharT_>
GetLineProxy_<CharT_*> get_line(CharT_* buffer_, LengthType capacity_) {
#	if __cplusplus >= 201103L
	return GetLineProxy_<CharT_*>{ buffer_, capacity_ };
#	else
	return GetLineProxy_<CharT_*>(buffer_, capacity_);
#	endif
}


template <typename CharT_>
GetUntilProxy_<CharT_*> get_until(CharT_* buffer_, CharT_ delimiter__, LengthType capacity_) {
#	if __cplusplus >= 201103L
	return GetUntilProxy_<CharT_*>{ buffer_, delimiter__, capacity_ };
#	else
	return GetUntilProxy_<CharT_*>(buffer_, delimiter__, capacity_);
#	endif
}



struct Scan {
	DD_ALIAS(ThisType, Scan);


#	if __cplusplus >= 201103L
	ThisType const& operator ()() const DD_NOEXCEPT {
		return *this;
	}

	template <typename ValueT__, typename... ValuesT__>
	ThisType const& operator ()(
		ValueT__ const& value___,
		ValuesT__ const&... values___
	) const DD_NOEXCEPT_AS((fabricate<ThisType>(), value___)(values___...)) {
		return (*this, value___)(values___...);
	}


#	endif
	template <typename ValueT__>
	ThisType const& operator ,(ValueT__& value___) const DD_NOEXCEPT_AS(std::cin >> value___) {
		std::cin >> value___;
		return *this;
	}


	template <typename CharT__>
	ThisType const& operator ,(GetLineProxy_<CharT__*> const& proxy_) const {
		std::cin.getline(proxy_.value_, proxy_.capacity_);
		return *this;
	}


	template <typename CharT__>
	ThisType const& operator ,(GetUntilProxy_<CharT__*> const& proxy_) const {
		std::cin.getline(proxy_.value_, proxy_.capacity_, proxy_.delimiter_);
		return *this;
	}


} DD_CONSTANT scan;



DD_DETAIL_END_



DD_BEGIN_
using detail_::get_line;
using detail_::get_until;
using detail_::Scan;
using detail_::scan;



DD_END_



#	define DD_SCAN ::DD::scan,



#endif
