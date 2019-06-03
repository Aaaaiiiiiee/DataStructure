#include "Node.h"



Node::Node(int key)
	: left_node(nullptr), right_node(nullptr), key(key), left_count(0), right_count(0)
{
}


Node::~Node()
{
}

Node * Node::GetLeftNode()
{
	return left_node;
}

Node * Node::GetRightNode()
{
	return right_node;
}

int Node::GetKey()
{
	return key;
}

void Node::SetLeftNode(Node * left_node)
{
	this->left_node = left_node;
}

void Node::SetRightNode(Node * right_node)
{
	this->right_node = right_node;
}

void Node::SetLeftCount(int left_count)
{
	this->left_count = left_count;
}

void Node::SetRightCount(int right_count)
{
	this->right_count = right_count;
}
