#include "Node.h"
#include <iostream>


Node::Node()
	: key(-1)
{
}

Node::Node(int key)
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

void Node::SetBefore(Node * before)
{
	this->before = before;
}

void Node::SetKey(int key)
{
	this->key = key;
}

Node * Node::GetNext()
{
	return next;
}

Node * Node::GetBefore()
{
	return before;
}

int Node::GetKey()
{
	return key;
}
