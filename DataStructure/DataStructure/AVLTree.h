#pragma once

class AVLTree
{
public:
	AVLTree();
	~AVLTree();

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
};

