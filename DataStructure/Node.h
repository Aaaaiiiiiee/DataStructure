#pragma once
class Node
{
public:
	Node * left_node;
	Node* right_node;
	int key;

	Node(int key);
	~Node();

	Node* GetLeftNode();
	Node* GetRightNode();
	int GetKey();
	void SetLeftNode(Node* left_node);
	void SetRightNode(Node* right_node);
};

