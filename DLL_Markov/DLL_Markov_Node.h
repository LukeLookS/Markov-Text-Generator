#pragma once
template<class T>
class DLL_Markov_Node
{
public:

	T getRandom() {
		int randnum = rand() % v.GetSize();
		return v.get(randnum);
	}

	void addNew(T t) {
		v.addback(t);
	}
	T info;
	Vector<T> v;
	DLL_Markov_Node<T> *next, *prev;
};