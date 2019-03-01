#pragma once
#include <iostream>
#include <cstdlib>
#include <string.h>  
#include <conio.h>  
#include <stdio.h> 
#include"IVector.h"
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

template<class T>
class VectorNode {
public:
	VectorNode<T>() {
		next = 0;
	}
	T info;
	VectorNode<T> *next;
};

template<class T>
class Vector:public IVector<T>
{
public:

	Vector() {
		head = tail = 0;
	}
	int GetSize() {
		// check to see if the list is empty. if 
		// so, just return 0
		if (IsEmpty()) return 0;

		int size = 1;
		VectorNode<T> *p = head;
		// compute the number of nodes and return
		while (p != tail)
		{
			// until we reach the tail, keep counting
			size++;
			p = p->next;
		}
		return size;
	}

	bool IsEmpty() {
		return (head == 0);
	}

	//void addback(const IntNode & node){
	void addback(T t) {
		VectorNode<T> *newPtr = new VectorNode<T>;
		newPtr->info = t; // create new node to store the parameter node
		if (IsEmpty()) { // check if the list is empty
			head = tail = newPtr;
		}
		else {
			tail->next = newPtr; //let the tail to point the node
			tail = newPtr;
			tail->next = NULL; //set the new tail point to NULL
		}
		if (head == 0)
			head = tail;
	}

	T get(int GetNum) {
		{
			T value;	
			VectorNode<T> *tmp = head;
			for (int i = 0; i < GetNum && tmp != tail; i++)
				tmp = tmp->next;
			value = tmp->info;
			return value;
		}
	}

private:
	VectorNode<T> *head, *tail;
};

