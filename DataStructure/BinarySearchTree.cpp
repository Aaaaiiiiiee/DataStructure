#include "BinarySearchTree.h"
//#include <stack>
#include <queue>

BinarySearchTree::BinarySearchTree()
	: root(nullptr)
{
}


BinarySearchTree::~BinarySearchTree()
{
	// postfix delete
	//stack<Node*> cur_delete;
	//Node* tmp = root;
	//cur_delete.push(tmp);
	//while (!cur_delete.empty())
	//{
	//	if (tmp->GetLeftNode() != nullptr)	// 왼쪽을 먼저 쭉 탐색
	//	{
	//		cur_delete.push(tmp->GetLeftNode());
	//		tmp = tmp->GetLeftNode();
	//	}
	//	else	// 더이상 왼쪽으로 갈 수 없을때
	//	{
	//		delete cur_delete.top();	// 해당 Node를 지우고
	//		cur_delete.top() = nullptr;
	//		cur_delete.pop();
	//
	//		// Node root를 pop한 경우를 예외처리 해야함
	//		if (cur_delete.empty())	break;
	//
	//		tmp = cur_delete.top();		// 그것의 parent node의 오른쪽 탐색
	//		if (tmp->GetRightNode() != nullptr)	// 오른쪽 탐색
	//		{
	//			cur_delete.push(tmp->GetRightNode());
	//			tmp = tmp->GetRightNode();
	//		}
	//		else	// 오른쪽을 더이상 볼 수 없을 때
	//		{
	//			delete cur_delete.top();
	//			cur_delete.top() = nullptr;
	//			cur_delete.pop();
	//			tmp = cur_delete.top();
	//		}
	//	}
	//}
	
	// root Node부터 시작하여 height별로 delete시켜줌. 
	queue<Node*> cur_delete;
	if (root != nullptr)
	{
		cur_delete.push(root);
		while (!cur_delete.empty())
		{
			Node* tmp = cur_delete.front();
			cur_delete.pop();
			if (tmp->GetLeftNode() != nullptr)
				cur_delete.push(tmp->GetLeftNode());
			else if (tmp->GetRightNode() != nullptr)
				cur_delete.push(tmp->GetRightNode());
			delete tmp;
		}
	}
}

Node * BinarySearchTree::Search(int key)
{
	Node* tmp = root;
	while (tmp != nullptr)	// O(log n)
	{
		if (tmp->GetKey() > key)
			tmp = tmp->GetLeftNode();
		else if (tmp->GetKey() < key)
			tmp = tmp->GetRightNode();
		else
			return tmp;
	}
	return tmp;	// nullptr 반환. 탐색 실패.
}

bool BinarySearchTree::Push(int key)
{
	Node* node_new = new Node(key);
	
	// root에 하나도 없을때. 예외처리.
	if (root == nullptr)
	{
		root = node_new;
		return true;
	}
	
	Node* tmp = root;
	Node* before = tmp;
	while (tmp != nullptr)	// O(log n)
	{
		if (tmp->GetKey() > key)
		{
			before = tmp;
			tmp = tmp->GetLeftNode();
		}
		else if (tmp->GetKey() < key)
		{
			before = tmp;
			tmp = tmp->GetRightNode();
		}
		else return false;
	}
	if (before->GetKey() > key)
		before->SetLeftNode(node_new);
	else
		before->SetRightNode(node_new);

	return true;
}

//bool BinarySearchTree::Delete(int key)
//{
//	Node* node_delete = Search(key);
//
//	if (node_delete != nullptr)
//	{
//		delete node_delete;
//		return true;
//	}
//	else
//		return false;
//}

// child가 0,1,2개 일때 따져서 delete해야함.

bool BinarySearchTree::DownTree(string sequence)
{
	Node* search = root;
	for (int i = 0; i < sequence.size(); i++)
	{
		switch (sequence[i])
		{
		case 'L':
			if (search->GetLeftNode() != nullptr)
				search = search->GetLeftNode();
			else
				return false;
			break;
		case 'R':
			if (search->GetRightNode() != nullptr)
				search = search->GetRightNode();
			else
				return false;
			break;
		}
	}
	
	return true;
}
