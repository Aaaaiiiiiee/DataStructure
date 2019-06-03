#pragma once

class AVLTree
{
public:
	AVLTree();
	~AVLTree();

	/*
	*	AVLTree bool Insert(int)
	*	Insert 성공 여부 반환
	*	true : Insert 성공
	*	false : Insert 실패
	*/
	bool Insert(int key);
	/*
	*	AVLTree bool Delete(int)
	*	Delete 성공 여부 반환
	*	true : Delete 성공
	*	false : Delete 실패
	*/
	bool Delete(int key);
};

