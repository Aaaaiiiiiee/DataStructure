#pragma once
#include "Node.h"
#include <string>
#include <iostream>
using namespace std;

class BinarySearchTree
{
public:
	Node * root;
	
	BinarySearchTree();
	~BinarySearchTree();

	/*
	*	BinarySearchTree int Search(int)
	*	key���� ������ �ִ� Node�� �ּҰ� ��ȯ
	*	nullptr ��ȯ�� Ž�� ����
	*/
	Node* Search(int key);
	/*
	*	BinarySearchTree bool Push(int)
	*	Push ���� ���� ��ȯ
	*	true : Push ����(��ġ�� key�� ����)
	*	false : Push ����(��ġ�� key�� ����)
	*/
	bool Push(int key);
	/*
	*	BinarySearchTree bool Delete(int)
	*	Delete ���� ���� ��ȯ
	*	true : Delete ����(��ġ�� key�� ����)
	*	false : Delete ����(��ġ�� key�� ����)
	*/
	bool Delete(int key);

	/*
	*	BinarySearchTree bool DownTree(string)
	*	sequence��� Tree�� Ž���� ���� ���� ��ȯ
	*	true : sequence��� Node�� ��� Ž����(sequence�� Node�� ��� ����)
	*	false : Ž�� ����
	*/
	bool DownTree(string sequence);
};

