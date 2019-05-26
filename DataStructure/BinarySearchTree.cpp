#include "BinarySearchTree.h"
#include <queue>
#include <stack>

enum { DELETE, INSERT };

//bool BinarySearchTree::SearchToInsert(Node *& node_new, Node *& parent)
//{
//	Node* tmp = root;
//	parent = tmp;
//	while (tmp != nullptr)	// O(log n)
//	{
//		if (tmp->GetKey() > node_new->GetKey())
//		{
//			parent = tmp;
//			tmp = tmp->GetLeftNode();
//		}
//		else if (tmp->GetKey() < node_new->GetKey())
//		{
//			parent = tmp;
//			tmp = tmp->GetRightNode();
//		}
//		else return false;	// �̹� �ش� key���� ���� Node�� �����ϴ� ���
//	}
//
//	if (parent->GetKey() > node_new->GetKey())
//		parent->SetLeftNode(node_new);
//	else
//		parent->SetRightNode(node_new);
//
//	// � sequence�� Ÿ�� leaf���� ������ �������� ������, �߰��� �����ϴ� ��츦 ������ �ʿ䰡 ����.
//	// ��, �־��� ��� linkedlist�� ��찡 ��.
//
//	return true;	// Insert�� ����
//
//}
//
//bool BinarySearchTree::SearchToDelete(Node *& node_delete, Node *& parent, int & key)
//{
//	Node* tmp = root;
//	parent = tmp;
//
//	while (tmp != nullptr)
//	{
//		if (tmp->GetKey() > key)
//		{
//			parent = tmp;
//			tmp = tmp->GetLeftNode();
//		}
//		else if (tmp->GetKey() < key)
//		{
//			parent = tmp;
//			tmp = tmp->GetRightNode();
//		}
//		else
//		{
//			node_delete = tmp;
//			return true;
//		}
//	}
//	return false;
//}

bool BinarySearchTree::SearchToInsertAndDelete(Node *& node, Node *& parent, const bool& insert_or_delete)
{
	Node* tmp = root;
	parent = tmp;

	while (tmp != nullptr)
	{
		if (tmp->GetKey() > node->GetKey())
		{
			parent = tmp;
			tmp = tmp->GetLeftNode();
		}
		else if (tmp->GetKey() < node->GetKey())
		{
			parent = tmp;
			tmp = tmp->GetRightNode();
		}
		else
		{
			if (insert_or_delete == DELETE)
			{
				delete node;
				node = tmp;
			}
			return insert_or_delete == INSERT ? false : true;	// Insert�� ���� ��� false ���� / Delete�� ���� ��� true ����
		}
	}

	// � sequence�� Ÿ�� leaf���� ������ �������� ������, �߰��� �����ϴ� ��츦 ������ �ʿ䰡 ����.
	// ��, �־��� ��� linkedlist�� ��찡 ��.

	return insert_or_delete == INSERT ? true : false;	// Insert�� ���� ��� true ���� / Delete�� ���� ��� false ����
}

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
	//	if (tmp->GetLeftNode() != nullptr)	// ������ ���� �� Ž��
	//	{
	//		cur_delete.push(tmp->GetLeftNode());
	//		tmp = tmp->GetLeftNode();
	//	}
	//	else	// ���̻� �������� �� �� ������
	//	{
	//		delete cur_delete.top();	// �ش� Node�� �����
	//		cur_delete.top() = nullptr;
	//		cur_delete.pop();
	//
	//		// Node root�� pop�� ��츦 ����ó�� �ؾ���
	//		if (cur_delete.empty())	break;
	//
	//		tmp = cur_delete.top();		// �װ��� parent node�� ������ Ž��
	//		if (tmp->GetRightNode() != nullptr)	// ������ Ž��
	//		{
	//			cur_delete.push(tmp->GetRightNode());
	//			tmp = tmp->GetRightNode();
	//		}
	//		else	// �������� ���̻� �� �� ���� ��
	//		{
	//			delete cur_delete.top();
	//			cur_delete.top() = nullptr;
	//			cur_delete.pop();
	//			tmp = cur_delete.top();
	//		}
	//	}
	//}
	
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
	//delete root;
}
// Node�� �Ҹ��ڰ� left_node, right_node delete�ε� ���⼭ delete root�� �ϸ� �� ���������� �Ǵ°� �ƴϾ�?
// �ƴϾ�! �׷��� Tree ������ ��, root Node�� Delete �õ��ϸ� tree�� �� �� ������..

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

bool BinarySearchTree::Insert(int key)
{
	Node* node_new = new Node(key);
	
	// root�� �ϳ��� ������. ����ó��.
	if (root == nullptr)
	{
		root = node_new;
		return true;
	}

	Node* parent;
	if (SearchToInsertAndDelete(node_new, parent, INSERT))
	{
		if (parent->GetKey() > node_new->GetKey())
			parent->SetLeftNode(node_new);
		else
			parent->SetRightNode(node_new);

		return true;
	}
	else
		return false;
}

bool BinarySearchTree::Delete(int key)
{
	// child�� 0,1,2�� �϶� ������ delete�ؾ���.
	Node* node_delete = new Node(key);
	Node* parent;

	if(SearchToInsertAndDelete(node_delete, parent, DELETE))
	{
		Node* left_node = node_delete->GetLeftNode();
		Node* right_node = node_delete->GetRightNode();
		
		// child�� ���� ��
		if (left_node == nullptr && right_node == nullptr)
		{
			if (parent->GetKey() > node_delete->GetKey())
				parent->SetLeftNode(nullptr);
			else if(parent->GetKey() < node_delete->GetKey())
				parent->SetRightNode(nullptr);
			/*else
			{
				cout << "�߻��� �� ���� ��Ȳ�Դϴ�." << endl;
				return 0;
			}*/

			if (node_delete == root)	root = nullptr;	// ����ó��
		}
		// ���ʿ��� child�� ������ ��
		else if (left_node != nullptr && right_node == nullptr)
		{
			if (parent->GetKey() > node_delete->GetKey())		// node_delete�� parent�� left_node�� ��
				parent->SetLeftNode(node_delete->GetLeftNode());
			else if(parent->GetKey() < node_delete->GetKey())	// node_delete�� parent Node�� right_node�� ��
				parent->SetRightNode(node_delete->GetLeftNode());
			/*else
			{
				cout << "�߻��� �� ���� ��Ȳ�Դϴ�." << endl;
				return 0;
			}*/

			if (node_delete == root)	root = left_node;
		}
		// �����ʿ��� child�� ������ ��
		else if (left_node == nullptr && right_node != nullptr)
		{
			if (parent->GetKey() > node_delete->GetKey())		// node_delete�� parent�� left_node�� ��
				parent->SetLeftNode(node_delete->GetRightNode());
			else if(parent->GetKey() < node_delete->GetKey())	// node_delete�� parent Node�� right_node�� ��
				parent->SetRightNode(node_delete->GetRightNode());
			/*else
			{
				cout << "�߻��� �� ���� ��Ȳ�Դϴ�." << endl;
				return 0;
			}*/

			if (node_delete == root)	root = right_node;
		}
		// �ΰ� �� child�� ������ ��
		else if(left_node != nullptr && right_node != nullptr)
		{
			Node* tmp = right_node;
			// delete_node�� right_node �߿��� ���� ���� ���� ã�� tmp�� �����Ѵ�.
			while (tmp->GetLeftNode() != nullptr)
				tmp = tmp->GetLeftNode();
			
			if (node_delete != root)
				// tmp�� delete_node�� parent Node�� �����Ų��.
				if (parent->GetKey() > node_delete->GetKey())
					parent->SetLeftNode(tmp);
				else
					parent->SetRightNode(tmp);
			// node_delete�� root�� �� ����ó��
			else
				root = tmp;
			
			// tmp�� left_node�� ���� �����Ƿ�, node_delete�� left_node�� tmp�� left_node�� �д�.
			tmp->SetLeftNode(left_node);

			if (tmp->GetRightNode() != nullptr)
			{
				// delete_node�� right_node�� �����ϱ� ����, ���� tmp���� ���� ū ���� ã�� tmp�� �����Ѵ�.
				while (tmp->GetRightNode() != nullptr)
					tmp = tmp->GetRightNode();
				// tmp�� right_node�� node_delete�� right_node�� �д�.
				tmp->SetRightNode(right_node);
			}
			
			// cf) ũ�� ���� : delete_node�� left_node < ���� ���� �� tmp(parent�� ������ tmp) < ���� ���� �� tmp�� right_node < delete_node�� right_node
			// ������ left_node�� right_node�� �ϳ��� tree�� ��� �����ص� �ȴ�.
		}
		
		delete node_delete;
		node_delete = nullptr;
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

void BinarySearchTree::PrintTree()
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

void BinarySearchTree::PrintTree(Node * node_print)
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
