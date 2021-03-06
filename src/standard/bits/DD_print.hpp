//	DDCPP/standard/bits/DD_print.hpp
#ifndef DD_PRINT_HPP_INCLUDED_
#	define DD_PRINT_HPP_INCLUDED_ 1



#	include <iostream>
#	include <iomanip>

#	include "DD_Tags.hpp"
#	include "DD_fabricate.hpp"



DD_DETAIL_BEGIN_
struct VersionTag : Tag {
} DD_CONSTANT version;



struct FlushTag : Tag {
} DD_CONSTANT flush;



struct EndLineTag : Tag {
} DD_CONSTANT end_line;



struct Print {
	public:
	DD_ALIAS(ThisType, Print);


#	if __cplusplus >= 201103L
	public:
	ThisType const& operator ()() const DD_NOEXCEPT {
		return *this;
	}

	public:
	template <typename ValueT__, typename... ValuesT__>
	ThisType const& operator ()(
		ValueT__ const& value___,
		ValuesT__ const&... values___
	) const DD_NOEXCEPT_AS((fabricate<ThisType>(), value___)(values___...)) {
		return (*this, value___)(values___...);
	}


#	endif
	public:
	template <typename ValueT__>
	ThisType const& operator ,(ValueT__ const& value___) const DD_NOEXCEPT_AS(std::cout << value___) {
		std::cout << value___;
		return *this;
	}

	public:
	ThisType const& operator ,(FlushTag tag_) const DD_NOEXCEPT_AS(std::cout << std::flush) {
		std::cout << std::flush;
		return *this;
	}

	public:
	ThisType const& operator ,(EndLineTag tag_) const DD_NOEXCEPT_AS(std::cout << std::endl) {
		std::cout << std::endl;
		return *this;
	}

	public:
	ThisType const& operator ,(VersionTag tag_) const DD_NOEXCEPT_AS(
		fabricate<ThisType>() DD_COMMA
		"libDDCPP\nversion: " DD_COMMA
		DD_CPP_LIBRARY / 1000 DD_COMMA
		'.' DD_COMMA
		DD_CPP_LIBRARY % 1000 / 100 DD_COMMA
		DD_CPP_LIBRARY % 100 / 10 DD_COMMA
		DD_CPP_LIBRARY % 10 DD_COMMA
		'\n'
	) {
		return
			*this,
			"libDDCPP\nversion: ",
			DD_CPP_LIBRARY / 1000,
			'.',
			DD_CPP_LIBRARY % 1000 / 100,
			DD_CPP_LIBRARY % 100 / 10,
			DD_CPP_LIBRARY % 10,
			'\n'
		;
	}


} DD_CONSTANT print;



DD_DETAIL_END_



DD_BEGIN_
using detail_::VersionTag;
using detail_::version;
using detail_::FlushTag;
using detail_::flush;
using detail_::EndLineTag;
using detail_::end_line;
using detail_::Print;
using detail_::print;



DD_END_



#	define DD_PRINT ::DD::print,



#endif
