#include "BinarySearchTree.h"
#include <stack>

BinarySearchTree::BinarySearchTree()
	: root(nullptr)
{
}


BinarySearchTree::~BinarySearchTree()
{
	stack<Node*> cur_delete;
	Node* tmp = root;
	cur_delete.push(tmp);
	while (!cur_delete.empty())
	{
		if (tmp->GetLeftNode() != nullptr)	// ������ ���� �� Ž��
		{
			cur_delete.push(tmp->GetLeftNode());
			tmp = tmp->GetLeftNode();
		}
		else	// ���̻� �������� �� �� ������
		{
			delete cur_delete.top();	// �ش� Node�� �����
			cur_delete.top() = nullptr;
			cur_delete.pop();

			// Node root�� pop�� ��츦 ����ó�� �ؾ���
			if (cur_delete.empty())	break;

			tmp = cur_delete.top();		// �װ��� parent node�� ������ Ž��
			if (tmp->GetRightNode() != nullptr)	// ������ Ž��
			{
				cur_delete.push(tmp->GetRightNode());
				tmp = tmp->GetRightNode();
			}
			else	// �������� ���̻� �� �� ���� ��
			{
				delete cur_delete.top();
				cur_delete.top() = nullptr;
				cur_delete.pop();
				tmp = cur_delete.top();
			}
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
	return tmp;	// nullptr ��ȯ. Ž�� ����.
}

bool BinarySearchTree::Push(int key)
{
	Node* node_new = new Node(key);
	
	// root�� �ϳ��� ������. ����ó��.
	if (root == nullptr)
	{
		root = node_new;
		return;
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

bool BinarySearchTree::Delete(int key)
{
	Node* node_delete = Search(key);

	if (node_delete != nullptr)
	{
		delete node_delete;
		return true;
	}
	else
		return false;
}

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
