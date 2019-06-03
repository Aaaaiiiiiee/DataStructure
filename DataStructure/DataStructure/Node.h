#pragma once
class Node
{
private : 
	Node * left_node;
	Node* right_node;
	int key;
	int left_count;
	int right_count;
public:
	Node(int key);
	~Node();

	Node* GetLeftNode();
	Node* GetRightNode();
	int GetKey();
	void SetLeftNode(Node* left_node);
	void SetRightNode(Node* right_node);
	void SetLeftCount(int left_count);
	void SetRightCount(int right_count);
};

