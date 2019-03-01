#pragma once

#include "SkipList_Markov_Node.h"

template<class T>
class Skiplist_Markov :public IMarkov<T> {
public:

	T generate(int num)
	{
		SkipList_Markov_Node<T> *temp = new SkipList_Markov_Node<T>;

		int size = 0;  //  the number of nodes
		if (sentinel->next[0] == NULL)
			return "The text file is empty!!!";
		else
		{
			size += 1;
			for (temp = sentinel->next[0]; temp->next[0] != NULL; temp = temp->next[0], size++);

			int r = rand() % size;  //  generate a random number


			temp = new SkipList_Markov_Node<T>;
			for (temp = sentinel->next[0]; r != 0; temp = temp->next[0], r--);  //  pick the random node

			T t = temp->info;

			for (int i = num - 1; i > 0; i--)
			{
				T flag = temp->getRandom();
				t += (" " + flag);

				temp = new SkipList_Markov_Node<T>;
				temp = NodeSearch(flag);   //  find the flag node

				if (temp == NULL)
					break;
			}
			return t;  //  the result
		}
	}

	void add(T t1, T t2)
	{
		if (sentinel != NULL)  //  the node is empty
		{

			SkipList_Markov_Node<T> *tempNode = new SkipList_Markov_Node<T>;

			if (NodeSearch(t1) == NULL)
			{
				int h = pickHeight();
				while (h > MAXLEVEL - 1)
					h = pickHeight();

				tempNode->height = h + 1;

				for (int i = tempNode->height - 1; i >= 0; i--)
				{
					tempNode->next[i] = sentinel->next[i];  //  insert the new node
					sentinel->next[i] = tempNode;
				}
				tempNode->info = t1;
				tempNode->addNew(t2);

				if (sentinel->height < tempNode->height)
					sentinel->height = tempNode->height;
			}

			else
			{
				tempNode = new SkipList_Markov_Node<T>;
				tempNode = NodeSearch(t1);  //  search the t1 node
				tempNode->addNew(t2);  //  addNew t2 to t1 vector
			}
		}
		else
		{
			int h1 = pickHeight();
			while (h1 > MAXLEVEL - 1)
				h1 = pickHeight();

			SkipList_Markov_Node<T> *firstNode = new SkipList_Markov_Node<T>;

			sentinel = new SkipList_Markov_Node<T>;

			for (int i = h1; i >= 0; i--)
			{
				firstNode->next[i] = 0;		     // insert the first node
				sentinel->next[i] = firstNode;
			}
			firstNode->info = t1;
			firstNode->addNew(t2);  //  add t2 to t1's vector

			sentinel->height = h1 + 1;
			firstNode->height = h1 + 1;
		}
	}


	SkipList_Markov_Node<T> *NodeSearch(T x) // search the node in the skiplist
	{
		SkipList_Markov_Node<T> *u = sentinel;
		int r = u->height;
		while (r >= 0) {
			u = sentinel->next[r];
			if (u != 0)
			{
				while (u->next[r] != NULL && u->info != x)
					u = u->next[r]; 
			}
			else if (u->info == x)
				return u;
			else {
				r--;
				u = sentinel;
			}
		}
			return NULL;
	}

	int pickHeight() {
		int z = rand();
		int k = 0;
		int m = 1;
		while ((z & m) != 0) {
			k++;
			m <<= 1;
		}
		return k;
	}

private:
	SkipList_Markov_Node<T> *sentinel;
};