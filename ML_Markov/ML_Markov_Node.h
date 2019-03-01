#pragma once
/////////////////////////////////////////////////////////////////////
// ML_Markov_Node.h                                                //
//                                                                 //
// Mengjie Shi, CSE674                                             //
// SUID:  457056896                                                //
/////////////////////////////////////////////////////////////////////
#include<cstdlib>
template<class T>
class ML_Markov_Node
{
public:

	ML_Markov_Node<T>* getRandom() {
		if (v.GetSize() != 0) {
			int randnum = rand() % v.GetSize();
			return v.get(randnum);
		}
		else {
			return NULL;
		}
	}

	void addNew(ML_Markov_Node<T>* t) {
		v.addback(t);
	}

	T info;
	Vector<ML_Markov_Node<T>*> v;
	ML_Markov_Node<T> *next, *prev;
};