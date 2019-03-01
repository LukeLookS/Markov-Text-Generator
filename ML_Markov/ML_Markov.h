#pragma once
#include"../IMarkov/IMarkov.h"
template <class T>
class ML_Markov_Node {
public:
	ML_Markov_Node<T>* getRandom() {

	}
	void addNew(ML_Markov_Node<T>*) v;
	T info;
	Vector<ML_Markov_Node<T>*> v;
	ML_Markov_Node<T> *next, *prev;
};

template<class T>
class ML_Markov :public IMarkov<T>
{
public:
	void add(T t1, T t2) {

	}
	T generate(int) {

	}
private:
	int size;
	ML_Markov_Node<T> *head, *tail;
};

