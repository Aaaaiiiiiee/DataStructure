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
	*	key값을 가지고 있는 Node의 주소값 반환
	*	nullptr 반환시 탐색 실패
	*/
	Node* Search(int key);
	/*
	*	BinarySearchTree bool Push(int)
	*	Push 성공 여부 반환
	*	true : Push 성공(겹치는 key값 없음)
	*	false : Push 실패(겹치는 key값 존재)
	*/
	bool Push(int key);
	/*
	*	BinarySearchTree bool Delete(int)
	*	Delete 성공 여부 반환
	*	true : Delete 성공(겹치는 key값 존재)
	*	false : Delete 실패(겹치는 key값 없음)
	*/
	bool Delete(int key);

	/*
	*	BinarySearchTree bool DownTree(string)
	*	sequence대로 Tree를 탐색해 성공 여부 반환
	*	true : sequence대로 Node를 모두 탐색함(sequence의 Node가 모두 존재)
	*	false : 탐색 실패
	*/
	bool DownTree(string sequence);
};

