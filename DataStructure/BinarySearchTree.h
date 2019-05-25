#pragma once
#include "Node.h"
#include <string>
#include <iostream>
using namespace std;

class BinarySearchTree
{
private : 
	Node * root;

	/*bool SearchToInsert(Node*& node_new, Node*& parent);
	bool SearchToDelete(Node*& node_delete, Node*& parent, int& key);*/
	/*
	*	BinarySearchTree::bool SearchToInsertAndDelete(Node*&, Node*&, bool)
	*	Insert�� Delete�� ���� Search �Լ�
	*	insert_or_delete�� true�̸�, Insert�� �ش��ϴ� �� ��ȯ(Insert�� �� ������ true, ������ false)
	*	insert_or_delete�� false�̸�, Delete�� �ش��ϴ� �� ��ȯ(Delete�� �� ������ true, ������ false)
	*	BinarySearchTree::bool SearchToInsert, BinarySearchTree::bool SearchToDelete ����
	*/
	bool SearchToInsertAndDelete(Node*& node, Node*& parent, bool insert_or_delete);	// true�� insert false�� delte
public:
	BinarySearchTree();
	~BinarySearchTree();

	/*
	*	BinarySearchTree::int Search(int)
	*	key���� ������ �ִ� Node�� �ּҰ� ��ȯ
	*	nullptr ��ȯ�� Ž�� ����
	*/
	Node* Search(int key);
	/*
	*	BinarySearchTree::bool Insert(int)
	*	Insert ���� ���� ��ȯ
	*	true : Insert ����(��ġ�� key�� ����)
	*	false : Insert ����(��ġ�� key�� ����)
	*/
	bool Insert(int key);
	/*
	*	BinarySearchTree::bool Delete(int)
	*	Delete ���� ���� ��ȯ
	*	true : Delete ����(��ġ�� key�� ����)
	*	false : Delete ����(��ġ�� key�� ����)
	*/
	bool Delete(int key);

	/*
	*	BinarySearchTree::bool DownTree(string)
	*	sequence��� Tree�� Ž���� ���� ���� ��ȯ
	*	true : sequence��� Node�� ��� Ž����(sequence�� Node�� ��� ����)
	*	false : Ž�� ����
	*/
	bool DownTree(string sequence);
};

