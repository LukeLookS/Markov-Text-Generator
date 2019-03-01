#pragma once
#include"../IVector/Vector.h"

template<class T>
class IMarkov {
public:
	virtual void add(T, T) = 0;
	virtual T generate(int) = 0;
	virtual ~IMarkov() {}
};