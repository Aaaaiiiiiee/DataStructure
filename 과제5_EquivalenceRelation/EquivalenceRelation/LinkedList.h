#pragma once
#include "Node.h"

class LinkedList
{
private : 
	Node* first;
	Node* end;
	Node* current;

public:
	LinkedList();
	~LinkedList();

	/*void Insert(int index);
	void Insert(int key, int index);*/
	void PushBack();
	void PushBack(int key);
	Node* operator[](int index);
	void MoveCurrentToFront();
	void MoveCurrentToBack();
	void SetCurrentBegin();
	Node* GetCurrent();
	Node* GetEnd();
};

