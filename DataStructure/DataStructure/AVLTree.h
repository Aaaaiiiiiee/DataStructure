#pragma once
#include "Node.h"

class AVLTree
{
private : 
	Node * root;

	void LLRotation();
	void LRRotation();
	void RRRotation();
	void RLRotation();
public:
	AVLTree();
	~AVLTree();

	/*
	*	AVLTree int Search(int)
	*	key���� ������ �ִ� Node�� �ּҰ� ��ȯ
	*	nullptr ��ȯ�� Ž�� ����
	*/
	Node* Search(int key);
	/*
	*	AVLTree bool Insert(int)
	*	Insert ���� ���� ��ȯ
	*	true : Insert ����
	*	false : Insert ����
	*/
	bool Insert(int key);
	/*
	*	AVLTree bool Delete(int)
	*	Delete ���� ���� ��ȯ
	*	true : Delete ����
	*	false : Delete ����
	*/
	bool Delete(int key);

	/*
	*	AVLTree void PrintTree()
	*	��ü Tree ���
	*/
	void PrintTree();
	/*
	*	AVLTree void PrintTree(Node*)
	*	node_print������ sequence(Tree) ���
	*/
	void PrintTree(Node* node_print);
};

