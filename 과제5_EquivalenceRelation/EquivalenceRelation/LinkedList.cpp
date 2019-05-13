#include "LinkedList.h"



LinkedList::LinkedList()
{
	first = new Node();
	end = new Node();
	first->SetNext(end);
	first->SetBefore(first);
	end->SetNext(end);
	end->SetBefore(first);
	
	current = first;	// current�� �ʱⰪ�� first�� ����Ŵ.
}


LinkedList::~LinkedList()
{
	Node* tmp = first;
	Node* next;
	while (tmp != end)
	{
		next = tmp->GetNext();
		delete tmp;
		tmp = next;
	}
	delete tmp;
}

//void LinkedList::Insert(int index)
//{
//	Insert(false, index);
//}
//
//void LinkedList::Insert(int key, int index)
//{
//	// index��° �ε����� key���� �ְڴ�.
//	Node* tmp = first->GetNext();
//	for (int i = 0; i < index; i++)
//		tmp = tmp->GetNext();
//	// ���� tmp�� next�� index��° node.
//
//	Node* insert = new Node(key);
//	insert->SetNext(tmp->GetNext());
//	insert->SetBefore(tmp);
//	tmp->SetNext(insert);
//}

void LinkedList::PushBack()
{
	PushBack(-1);
}

/*
*	LinkedList::PushBack(int key)
*	current �ٷ� ������ push��.
*/
void LinkedList::PushBack(int key)
{
	Node* insert = new Node(key);
	insert->SetNext(current->GetNext());
	current->SetNext(insert);
	current = insert;
}

/*
*	LinkedList::operator[](int index)
*	O(n)
*/
Node* LinkedList::operator[](int index)
{
	Node* tmp = first->GetNext();
	for (int i = 0; i <= index; i++)
		tmp = tmp->GetNext();

	return tmp;
}

void LinkedList::MoveCurrentToFront()
{
	current = current->GetBefore();
}

void LinkedList::MoveCurrentToBack()
{
	current = current->GetNext();
}

void LinkedList::SetCurrentBegin()
{
	current = first;
}

Node* LinkedList::GetCurrent()
{
	return current;
}

Node * LinkedList::GetEnd()
{
	return end;
}
