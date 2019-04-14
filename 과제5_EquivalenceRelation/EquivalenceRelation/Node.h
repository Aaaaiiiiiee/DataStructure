#pragma once
class Node
{
private : 
	Node * next;
	const int key;
public:
	Node();
	Node(const int& key);
	~Node();

	void SetNext(Node* next);
	Node* GetNext();
	int GetKey();
};

