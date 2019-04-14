#include "Node.h"



Node::Node()
{
}

Node::Node(const int & key)
	: key(key)
{
}


Node::~Node()
{
}

void Node::SetNext(Node * next)
{
	this->next = next;
}

Node * Node::GetNext()
{
	return next;
}

int Node::GetKey()
{
	return key;
}
