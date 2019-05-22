#include "Node.h"



//Node::Node()
//{
//}


Node::Node(int key)
	: left_node(nullptr), right_node(nullptr), key(key)
{
}

Node::~Node()
{
	delete left_node;
	delete right_node;
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
