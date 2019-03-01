#pragma once
template<class T>
class IVector {
public:
	virtual int GetSize() = 0;
	virtual bool IsEmpty() = 0;
	virtual void addback(T) = 0;
	virtual T get(int) = 0;
	virtual ~IVector() {}
};


