//	DDCPP/standard/DDMemory.hpp
#ifndef _DDMEMORY_HPP_INCLUDED
#	define _DDMEMORY_HPP_INCLUDED 1



#	include "bits/DD_size_distance.hpp"
#	include "bits/DD_DefaultDeleter.hpp"
#	include "bits/DD_FreeList.hpp"
#	if __cplusplus >= 201103L
#		include "bits/DD_make_unique.hpp"
#		include "bits/DD_make_parasitic.hpp"
#	else
#		include "bits/DD_UniquePointer.hpp"
#		include "bits/DD_ParasiticPointer.hpp"
#	endif



#endif
