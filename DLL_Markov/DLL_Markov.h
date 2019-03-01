#pragma once
#include"../IMarkov/IMarkov.h"
#include"../DLL_Markov/DLL_Markov_Node.h"
#include"../IVector/Vector.h"
#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

template<class T>
class DLL_Markov :public IMarkov<T> {
public:
	void add(T t1, T t2) {
		DLL_Markov_Node<T> *tmp = new DLL_Markov_Node<T>;
		//DLL_Markov_Node<T> dll = new DLL_Markov_Node<T>;
		if (tail != NULL) {
			for (tmp = head; tmp != tail; tmp = tmp->next) {
				if (tmp->info == t1)
					break;
			}
			if (tmp == tail && tmp->info != t1) {
				tmp = new DLL_Markov_Node<T>;
				tmp->info = t1;
				tmp->prev = tail;
				tmp->next = NULL;
				tail = tmp;
				tail->prev->next = tail;
				tmp = tail;
			}
			tmp->addNew(t2);
		}
			else
			{
				head = tail = tmp;
				head->info = t1;
				head->addNew(t2);
			}
	}

	T generate(int num) {
		DLL_Markov_Node<T> *tmp = new DLL_Markov_Node<T>;
		int size = 0;
		if (tail == NULL)
			return "empty text file";
		else {
			size += 1;
			for (tmp = head; tmp != tail; tmp = tmp->next, size++)
				srand(time(0));
			int r = rand() % size;
			tmp = new DLL_Markov_Node<T>;
			for (tmp = head; r != 0; tmp = tmp->next, r--);
			T t = tmp->info;
			for (int i = num - 1; i > 0; i--)
			{ 
			T a = tmp->getRandom();
			t += (" " + a);
			tmp = new DLL_Markov_Node<T>;
			for (tmp = head; tmp->info != a&&tmp->next != NULL; tmp = tmp->next); 
				if (tmp->info != a)
					break;
			}
			return t;
		}
	}

private:
	DLL_Markov_Node<T> *head, *tail;  
};


#endif
