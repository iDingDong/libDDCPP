//	DDCPP/standard/bits/DD_WeakPointer.hpp
#ifndef DD_WEAK_POINTER_HPP_INCLUDED_
#	define DD_WEAK_POINTER_HPP_INCLUDED_ 1



#	include "DD_StrongPointer.hpp"



DD_DETAIL_BEGIN_
template <>
struct WeakPointer<void> {
	public:
	DD_ALIAS(ThisType, WeakPointer<void>);
	DD_VALUE_TYPE_NESTED(void);

	public:
	DD_SPECIFIC_TYPE_NESTED(Manager, ReferenceManagerBase_);

	public:
	DD_ALIAS(StrongType, StrongPointer<ValueType>);


	private:
	ManagerPointerType m_manager_pointer_ DD_IN_CLASS_INITIALIZE(get_nil_reference_manager_());


	public:
#	if __cplusplus >= 201103L
	WeakPointer() = default;
#	else
	WeakPointer() throw() : m_manager_pointer_(get_nil_reference_manager_()) {
	}
#	endif

	public:
	WeakPointer(ThisType const& origin_) DD_NOEXCEPT : m_manager_pointer_(origin_.get_manager_pointer_()) {
		get_manager_pointer_()->weakly_referred_();
	}

	public:
	WeakPointer(ThisType&& origin_) DD_NOEXCEPT : m_manager_pointer_(origin_.get_manager_pointer_()) {
		origin_.m_manager_pointer_ = get_nil_reference_manager_();
	}

	public:
	WeakPointer(
		StrongPointer<ValueType> const& strong_pointer_
	) DD_NOEXCEPT : m_manager_pointer_(strong_pointer_.get_manager_pointer_()) {
		get_manager_pointer_()->weakly_referred_();
	}

	private:
	WeakPointer(ManagerPointerType manager_pointer_) DD_NOEXCEPT : m_manager_pointer_(manager_pointer_) {
		get_manager_pointer_()->weakly_referred_();
	}

#	if __cplusplus >= 201103L
	private:
	WeakPointer(UnguardedTag tag_, ManagerPointerType manager_pointer_) DD_NOEXCEPT : m_manager_pointer_(manager_pointer_) {
	}

#	endif


	public:
	~WeakPointer() DD_NOEXCEPT {
		destruct_();
	}


	private:
	static ManagerPointerType get_nil_reference_manager_() DD_NOEXCEPT {
		return ManagerType::get_nil_reference_manager_();
	}


	protected:
	ManagerPointerType get_manager_pointer_() const DD_NOEXCEPT {
		return m_manager_pointer_;
	}


	public:
	LengthType get_strong_reference_count() const DD_NOEXCEPT {
		return get_manager_pointer_()->get_strong_reference_count_();
	}


	public:
	LengthType get_weak_reference_count() const DD_NOEXCEPT {
		return get_manager_pointer_()->get_weak_reference_count_();
	}


	public:
	ValidityType is_valid() const DD_NOEXCEPT {
		return get_strong_reference_count();
	}


	public:
	ValidityType is_expired() const DD_NOEXCEPT {
		return !is_valid();
	}


	public:
	StrongType lock() const DD_NOEXCEPT {
		return is_valid() ? StrongType(get_manager_pointer_()) : StrongType();
	}


	public:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT {
		::DD::swap(m_manager_pointer_, other_.m_manager_pointer_);
	}


	public:
	ProcessType reset() DD_NOEXCEPT {
		ThisType temp_;
		swap(temp_);
	}

	public:
	ProcessType reset(ThisType const& origin_) DD_NOEXCEPT {
		ThisType temp_(origin_);
		swap(temp_);
	}

#	if __cplusplus >= 201103L
	public:
	ProcessType reset(ThisType&& origin_) noexcept {
		swap(origin_);
	}
#	endif


	private:
	ProcessType destruct_() DD_NOEXCEPT {
		get_manager_pointer_()->weakly_released_();
	}


	public:
	ThisType& operator =(ThisType const& origin_) DD_NOEXCEPT {
		reset(origin_);
		return *this;
	}

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& origin_) noexcept {
		reset(::DD::move(origin_));
		return *this;
	}

#	endif

#	if __cplusplus >= 201103L
	public:
	explicit operator ValidityType() const DD_NOEXCEPT {
		return is_valid();
	}


#	endif
};



template <typename ValueT_>
struct WeakPointer : WeakPointer<void> {
	public:
	DD_ALIAS(SuperType, WeakPointer<void>);
	DD_ALIAS(ThisType, WeakPointer<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_);

	public:
	DD_ALIAS(StrongType, StrongPointer<ValueType>);
	DD_ALIAS(ConstStrongType, StrongPointer<ValueConstType>);
	DD_ALIAS(ConstWeakType, WeakPointer<ValueConstType>);

	private:
	DD_SPECIFIC_TYPE_NESTED(Manager, ReferenceManagerBase_);


	public:
	friend StronglyReferable<ValueT_>;
	friend WeakPointer<DD_MODIFY_TRAIT(RemoveConst, ValueType)>;


#	if __cplusplus >= 201103L
	public:
	WeakPointer() = default;

	public:
	WeakPointer(ThisType const& origin_) = default;

	public:
	WeakPointer(ThisType&& origin_) = default;
#	else
	public:
	WeakPointer() throw() : SuperType(get_nil_reference_manager_()) {
	}
#	endif

	public:
	WeakPointer(StrongType const& strong_pointer_) DD_NOEXCEPT : SuperType(strong_pointer_) {
	}

	private:
	WeakPointer(ManagerPointerType manager_pointer_) DD_NOEXCEPT : SuperType(manager_pointer_) {
	}

#	if __cplusplus >= 201103L
	private:
	WeakPointer(UnguardedTag tag_, ManagerPointerType manager_pointer_) DD_NOEXCEPT : SuperType(tag_, manager_pointer_) {
	}

#	endif

	public:
	ConstWeakType get_const_weak_pointer() const DD_CALLABLE_WITH_LVALUE_ONLY DD_NOEXCEPT {
		return ConstWeakType(get_manager_pointer_());
	}

#	if __cplusplus >= 201103L
	public:
	ConstWeakType get_const_weak_pointer() const DD_CALLABLE_WITH_RVALUE_ONLY DD_NOEXCEPT {
		ManagerPointerType manager_pointer_ = get_manager_pointer_();
		m_manager_pointer_ = get_nil_reference_manager_();
		return ConstWeakType(unguarded_tag, manager_pointer_);
	}

#	endif

	public:
	StrongType lock() const DD_NOEXCEPT {
		return is_valid() ? StrongType(get_manager_pointer_()) : StrongType();
	}


	public:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT {
		SuperType::swap(other_);
	}


	public:
	ProcessType reset() DD_NOEXCEPT {
		ThisType temp_;
		swap(temp_);
	}

#	if __cplusplus >= 201103L
	public:
	ProcessType reset(ThisType&& origin_) noexcept {
		swap(origin_);
	}

	public:
	template <typename ObjectT_>
	ProcessType reset(ObjectT_&& object__) noexcept(noexcept(ThisType(::DD::forward<ObjectT_>(object__)))) {
		ThisType temp_(::DD::forward<ObjectT_>(object__));
		swap(temp_);
	}
#	else
	public:
	template <typename ObjectT_>
	ProcessType reset(ObjectT_ const& object__) {
		ThisType temp_(object__);
		swap(temp_);
	}
#	endif


	private:
	ProcessType set_manager_(ManagerPointerType manager_pointer_) DD_NOEXCEPT {
		m_manager_pointer_ = manager_pointer_;
	}


	public:
	ThisType& operator =(ThisType const& origin_) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().reset(origin_)) {
		reset(origin_);
		return *this;
	}

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& origin_) noexcept(noexcept(::DD::fabricate<ThisType>().reset(::DD::move(origin_)))) {
		reset(::DD::move(origin_));
		return *this;
	}

	public:
	template <typename ObjectT__>
	ThisType& operator =(ObjectT__&& object___) noexcept(
		noexcept(::DD::fabricate<ThisType>().reset(::DD::forward<ObjectT__>(object___)))
	) {
		reset(::DD::forward<ObjectT__>(object___));
		return *this;
	}
#	else
	public:
	template <typename ObjectT__>
	ThisType& operator =(ObjectT__ const& object___) {
		reset(object___);
		return *this;
	}
#	endif


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::WeakPointer;



DD_END_



#endif
