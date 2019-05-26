#pragma once
#include "Node.h"
#include <string>
#include <queue>
#include <iostream>
using namespace std;

class BinarySearchTree
{
private : 
	Node * root;

	/*bool SearchToInsert(Node*& node_new, Node*& parent);
	bool SearchToDelete(Node*& node_delete, Node*& parent, int& key);*/

	/*
	*	BinarySearchTree bool SearchToInsertAndDelete(Node*&, Node*&, bool)
	*	Insert와 Delete를 위한 Search 함수
	*	insert_or_delete가 true이면, Insert에 해당하는 값 반환(Insert할 수 있으면 true, 없으면 false)
	*	insert_or_delete가 false이면, Delete에 해당하는 값 반환(Delete할 수 있으면 true, 없으면 false)
	*	BinarySearchTree::bool SearchToInsert, BinarySearchTree::bool SearchToDelete 참고
	*/
	bool SearchToInsertAndDelete(Node*& node, Node*& parent, bool insert_or_delete);
public:
	BinarySearchTree();
	~BinarySearchTree();

	/*
	*	BinarySearchTree int Search(int)
	*	key값을 가지고 있는 Node의 주소값 반환
	*	nullptr 반환시 탐색 실패
	*/
	Node* Search(int key);
	/*
	*	BinarySearchTree bool Insert(int)
	*	Insert 성공 여부 반환
	*	true : Insert 성공(겹치는 key값 없음)
	*	false : Insert 실패(겹치는 key값 존재)
	*/
	bool Insert(int key);
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

	/*
	*	BinarySearchTree void PrintTree()
	*	전체 Tree 출력
	*/
	void PrintTree();
	void PrintTree(Node* cur);

	/*
	*	BinarySearchTree void PrintTree(Node*)
	*	node_print까지의 sequence(Tree) 출력
	*/
	void PrintTree(Node* node_print);
};

