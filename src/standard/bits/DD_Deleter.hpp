//	DDCPP/standard/bits/DD_Deleter.hpp
#ifndef DD_DELETER_HPP_INCLUDED_
#	define DD_DELETER_HPP_INCLUDED_ 1



#	include "DD_Value.hpp"
#	include "DD_destruct.hpp"
#	include "DD_Allocateable.hpp"



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename AllocatorT_ = Allocator<void>>
#	else
template <typename AllocatorT_ = Allocator<void> >
#	endif
struct Deleter : protected Allocateable<AllocatorT_> {
	public:
	DD_ALIAS(AllocateAgent, Allocateable<AllocatorT_>);
	DD_ALIAS(ThisType, Deleter<AllocatorT_>);
	DD_ALIAS(AllocatorType, AllocatorT_);


#	if __cplusplus >= 201103L
	public:
	constexpr Deleter() = default;

	public:
	constexpr Deleter(ThisType const& origin_) = default;

	public:
	constexpr Deleter(ThisType&& origin_) = default;
#	else
	public:
	Deleter() {
	}
#	endif

	public:
	constexpr Deleter(AllocatorType const& allocator_) DD_NOEXCEPT_AS(AllocateAgent(allocator_)) : AllocateAgent(allocator_) {
	}


#	if __cplusplus >= 201103L
	public:
	~Deleter() = default;


#	endif
	public:
	AllocatorType& get_allocator() const DD_NOEXCEPT {
		return AllocateAgent::get_allocator();
	}


	public:
	template <typename ValueT__>
	ProcessType call(ValueT__* pointer_) const DD_NOEXCEPT {
		DD_ALIAS(PointerType_, ValueT__*);
		if (pointer_ != PointerType_()) {
			::DD::destruct(pointer_);
			AllocateAgent::basic_deallocate(pointer_, sizeof(ValueT__));
		}
	}


	public:
	template <typename ValueT__>
	ProcessType operator ()(ValueT__* pointer_) const DD_NOEXCEPT {
		call(pointer_);
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Deleter;



DD_END_



#endif
