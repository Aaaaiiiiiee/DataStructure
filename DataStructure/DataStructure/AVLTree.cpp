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
	// root Node���� �����Ͽ� height���� delete������. 
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
	return tmp;	// nullptr ��ȯ. Ž�� ����.
}

bool AVLTree::Insert(int key)
{
	Node* node_new = new Node(key);

	// Tree�� Node�� �ϳ��� ������. ����ó��.
	if (root == nullptr)
	{
		root = node_new;
		return true;
	}

	Node* tmp = root;
	Node* parent = tmp;
	stack<Node*> s;	s.push(parent);
	// left,right_count ���� ������Ű�鼭 �������� �ȵǴ°�, insert�� �������� ������ �𸥴�.
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

	// ������ ������ ���
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

		// Marker ���� �ٲ��ش�. �̶� AVLTree�� ���ǿ� ��߳��� Rotation�� �Ѵ�.
		int marker = 0;	Node* child = nullptr;
		while (!s.empty())
		{
			Node* cur = s.top();	s.pop();

			// leaf�� ���� ����ó��.(��� Insert�� ��)
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
	// ������ �Ұ����� ���
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
