#pragma once
#include "Node.h"

class LinkedList
{
private : 
	Node* first;
	Node* end;

public:
	LinkedList();
	~LinkedList();

	void Insert(int key, int index);
	void PushBack(int key);
	int operator[](int index);
};

