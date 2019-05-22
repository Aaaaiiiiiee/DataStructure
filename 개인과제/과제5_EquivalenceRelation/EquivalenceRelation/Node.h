#pragma once
class Node
{
private : 
	Node * next;
	Node* before;
	int key;
public:
	Node();
	Node(int key);
	~Node();

	void SetNext(Node* next);
	void SetBefore(Node* before);
	void SetKey(int key);
	Node* GetNext();
	Node* GetBefore();
	int GetKey();
};

