#include <stack>
#include <iostream>
#include <queue>
#include "AVLTree.h"
using namespace std;


AVLTree::AVLTree()
	: root(nullptr)
{
}


AVLTree::~AVLTree()
{
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

Node * AVLTree::Search(int key)
{
	Node* tmp = root;
	while (tmp != nullptr)
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

bool AVLTree::Insert(int key)
{
	Node* node_new = new Node(key);

	// Tree에 Node가 하나도 없을때. 예외처리.
	if (root == nullptr)
	{
		root = node_new;
		return true;
	}

	Node* tmp = root;
	Node* parent = tmp;
	stack<Node*> s;	s.push(parent);
	// left,right_count 값을 증가시키면서 내려가면 안되는게, insert에 성공할지 안할지 모른다.
	while (tmp != nullptr)
	{
		if (tmp->GetKey() > key)
		{
			parent = tmp;
			s.push(parent);
			tmp = tmp->GetLeftNode();
		}
		else if (tmp->GetKey() < key)
		{
			parent = tmp;
			s.push(parent);
			tmp = tmp->GetRightNode();
		}
		else break;
	}

	// 대입이 가능한 경우
	if (tmp == nullptr)
	{
		if (parent->GetKey() > key)
			parent->SetLeftNode(node_new);
		else if (parent->GetKey() < key)
			parent->SetRightNode(node_new);
		else
		{
			cout << "Can't Occur" << endl;
			return false;
		}

		// Marker 값을 바꿔준다. 이때 AVLTree의 정의에 어긋나면 Rotation을 한다.
		int marker = 0;	Node* child = nullptr;
		while (!s.empty())
		{
			Node* cur = s.top();	s.pop();

			// leaf에 대해 예외처리.(방금 Insert한 것)
			if (child == nullptr)	continue;
			
			if (cur->GetKey() > child->GetKey())
				cur->SetLeftCount(marker);
			else if (cur->GetKey() < child->GetKey())
				cur->SetRightCount(marker);
			else
			{
				cout << "Can't Occur" << endl;
				return false;
			}
			
			child = cur;
			marker++;
		}

		return true;
	}
	// 대입이 불가능한 경우
	else
		return false;
}

bool AVLTree::Delete(int key)
{
	Node* node_delete = new Node(key);
}

void AVLTree::PrintTree()
{
	if (root != nullptr)
	{
		queue<Node*> q;
		q.push(root);
		cout << "root node " << root->GetKey() << endl;
		while (!q.empty())
		{
			Node* tmp = q.front();	q.pop();
			if (tmp->GetLeftNode() != nullptr)
			{
				cout << tmp->GetKey() << " left_node " << tmp->GetLeftNode()->GetKey() << endl;
				q.push(tmp->GetLeftNode());
			}
			if (tmp->GetRightNode() != nullptr)
			{
				cout << tmp->GetKey() << " right_node " << tmp->GetRightNode()->GetKey() << endl;
				q.push(tmp->GetRightNode());
			}
		}
	}
	else
		cout << "Node is not existed" << endl;
}

void AVLTree::PrintTree(Node * node_print)
{
	Node* tmp = root;
	cout << "root node" << root->GetKey() << endl;
	while (tmp->GetKey() != node_print->GetKey())
	{
		cout << tmp->GetKey();
		if (tmp->GetKey() > node_print->GetKey())
		{
			tmp = tmp->GetLeftNode();
			cout << " left_node " << tmp->GetKey() << endl;
		}
		else if (tmp->GetKey() < node_print->GetKey())
		{
			tmp = tmp->GetRightNode();
			cout << " right_node " << tmp->GetKey() << endl;
		}
	}
}
