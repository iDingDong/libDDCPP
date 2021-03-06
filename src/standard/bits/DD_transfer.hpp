//	DDCPP/standard/bits/DD_transfer.hpp
#ifndef DD_TRANSFER_HPP_INCLUDED_
#	define DD_TRANSFER_HPP_INCLUDED_



#	include "DD_transfer_backward.hpp"



DD_DETAIL_BEGIN_
template <typename FreeAccessIteratorT_>
ProcessType transfer(
	FreeAccessIteratorT_ from_,
	FreeAccessIteratorT_ to_
) {
	if (to_ < from_) {
		::DD::transfer_backward(from_, to_);
	} else {
		::DD::transfer_forward(from_, to_);
	}
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::transfer;



DD_END_



#endif
