#include "LinkedList.h"



LinkedList::LinkedList()
{
	first = new Node();
	end = new Node();
	first->SetNext(end);
	first->SetBefore(first);
	end->SetNext(end);
	end->SetBefore(first);
	
	current = first;	// current의 초기값은 first를 가르킴.
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
//	// index번째 인덱스에 key값을 넣겠다.
//	Node* tmp = first->GetNext();
//	for (int i = 0; i < index; i++)
//		tmp = tmp->GetNext();
//	// 현재 tmp의 next는 index번째 node.
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
*	current 바로 다음에 push함.
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
