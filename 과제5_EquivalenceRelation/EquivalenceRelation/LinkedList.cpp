#include "LinkedList.h"



LinkedList::LinkedList()
{
	first = new Node();
	end = new Node();
	first->SetNext(end);
	end->SetNext(end);
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

void LinkedList::Insert(int key, int index)
{
	// index��° �ε����� key���� �ְڴ�.
	Node* tmp = first;
	for (int i = 0; i <= index; i++)
		tmp->SetNext(tmp->GetNext());
	// ���� tmp�� next�� index��° node.

	Node* insert = new Node(key);
	insert->SetNext(tmp->GetNext());
	tmp->SetNext(insert);
}

void LinkedList::PushBack(int key)
{
	Node* tmp = first;
	while (tmp->GetNext() != end)
		tmp->SetNext(tmp->GetNext());
	// tmp�� end�� �ٷ� �� ���� ����ų ������ �ݺ�
	
	Node* insert = new Node(key);
	tmp->SetNext(insert);
	insert->SetNext(end);
}

int LinkedList::operator[](int index)
{
	Node* tmp = first->GetNext();
	for (int i = 0; i <= index; i++)
		tmp->SetNext(tmp->GetNext());

	return tmp->GetKey();
}
