#pragma once
class Node
{
private : 
	Node * left_node;
	Node* right_node;
	int key;
public:
	Node(int key);
	~Node();

	Node* GetLeftNode();
	Node* GetRightNode();
	int GetKey();
	void SetLeftNode(Node* left_node);
	void SetRightNode(Node* right_node);
};

