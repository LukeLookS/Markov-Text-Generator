#pragma once
#include "../IVector/Vector.h"
#include "../IMarkov/IMarkov.h"
template <class T>
struct SkipList_Markov_Node{
	Vector<T> v;
	T info;
	int height;  
	SkipList_Markov_Node<T> * next[10]; 

	T getRandom(){
		int randnum = rand() % v.size();
		return v.get(randnum);
	}

	void addNew(T t){
		v.addBack(t);
	}
};
