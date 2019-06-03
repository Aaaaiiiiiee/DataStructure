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
	*	key값을 가지고 있는 Node의 주소값 반환
	*	nullptr 반환시 탐색 실패
	*/
	Node* Search(int key);
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

	/*
	*	AVLTree void PrintTree()
	*	전체 Tree 출력
	*/
	void PrintTree();
	/*
	*	AVLTree void PrintTree(Node*)
	*	node_print까지의 sequence(Tree) 출력
	*/
	void PrintTree(Node* node_print);
};

