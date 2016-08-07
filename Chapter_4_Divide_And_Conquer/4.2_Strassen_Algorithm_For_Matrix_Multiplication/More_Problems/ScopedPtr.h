#ifndef ALGORITHMS_CHAPTER4_4_2_MORE_PROBLEMS_SCOPED_PTR_H_
#define ALGORITHMS_CHAPTER4_4_2_MORE_PROBLEMS_SCOPED_PTR_H_

template <typename T>
class ScopedPtr {
public:
	ScopedPtr(new T ptr);
	~ScopedPtr();

	T* Get() const;

private:
	// Doesn't want a copyable one.
	// restrict the copy constructor and copy assignment operator.

	ScopedPtr(const ScopedPtr<T>& ptr) {}
	ScopedPtr<T>& operator = (const ScopedPtr<T>& ptr) {}
	
	// Scoped pointer container.
	T* m_ptr;
};

template <typename T>
ScopedPtr<T>::ScopedPtr(new T ptr) : m_ptr(ptr) {}

template <typename T>
ScopedPtr<T>::

#endif ALGORITHMS_CHAPTER4_4_2_MORE_PROBLEMS_SCOPED_PTR_H_
