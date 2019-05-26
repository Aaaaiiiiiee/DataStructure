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
//		else return false;	// 이미 해당 key값을 가진 Node가 존재하는 경우
//	}
//
//	if (parent->GetKey() > node_new->GetKey())
//		parent->SetLeftNode(node_new);
//	else
//		parent->SetRightNode(node_new);
//
//	// 어떤 sequence를 타던 leaf까지 무조건 내려가기 때문에, 중간에 삽입하는 경우를 걱정할 필요가 없음.
//	// 단, 최악의 경우 linkedlist의 경우가 됨.
//
//	return true;	// Insert에 성공
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
			return insert_or_delete == INSERT ? false : true;	// Insert할 때의 경우 false 리턴 / Delete할 때의 경우 true 리턴
		}
	}

	// 어떤 sequence를 타던 leaf까지 무조건 내려가기 때문에, 중간에 삽입하는 경우를 걱정할 필요가 없음.
	// 단, 최악의 경우 linkedlist의 경우가 됨.

	return insert_or_delete == INSERT ? true : false;	// Insert할 때의 경우 true 리턴 / Delete할 때의 경우 false 리턴
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
	//delete root;
}
// Node의 소멸자가 left_node, right_node delete인데 여기서 delete root만 하면 쭉 연쇄적으로 되는거 아니야?
// 아니야! 그러면 Tree 존재할 때, root Node를 Delete 시도하면 tree가 싹 다 지워져..

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

bool BinarySearchTree::Insert(int key)
{
	Node* node_new = new Node(key);
	
	// root에 하나도 없을때. 예외처리.
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
	// child가 0,1,2개 일때 따져서 delete해야함.
	Node* node_delete = new Node(key);
	Node* parent;

	if(SearchToInsertAndDelete(node_delete, parent, DELETE))
	{
		Node* left_node = node_delete->GetLeftNode();
		Node* right_node = node_delete->GetRightNode();
		
		// child가 없을 때
		if (left_node == nullptr && right_node == nullptr)
		{
			if (parent->GetKey() > node_delete->GetKey())
				parent->SetLeftNode(nullptr);
			else if(parent->GetKey() < node_delete->GetKey())
				parent->SetRightNode(nullptr);
			/*else
			{
				cout << "발생할 수 없는 상황입니다." << endl;
				return 0;
			}*/

			if (node_delete == root)	root = nullptr;	// 예외처리
		}
		// 왼쪽에만 child가 존재할 때
		else if (left_node != nullptr && right_node == nullptr)
		{
			if (parent->GetKey() > node_delete->GetKey())		// node_delete가 parent의 left_node일 때
				parent->SetLeftNode(node_delete->GetLeftNode());
			else if(parent->GetKey() < node_delete->GetKey())	// node_delete가 parent Node의 right_node일 때
				parent->SetRightNode(node_delete->GetLeftNode());
			/*else
			{
				cout << "발생할 수 없는 상황입니다." << endl;
				return 0;
			}*/

			if (node_delete == root)	root = left_node;
		}
		// 오른쪽에만 child가 존재할 때
		else if (left_node == nullptr && right_node != nullptr)
		{
			if (parent->GetKey() > node_delete->GetKey())		// node_delete가 parent의 left_node일 때
				parent->SetLeftNode(node_delete->GetRightNode());
			else if(parent->GetKey() < node_delete->GetKey())	// node_delete가 parent Node의 right_node일 때
				parent->SetRightNode(node_delete->GetRightNode());
			/*else
			{
				cout << "발생할 수 없는 상황입니다." << endl;
				return 0;
			}*/

			if (node_delete == root)	root = right_node;
		}
		// 두곳 다 child가 존재할 때
		else if(left_node != nullptr && right_node != nullptr)
		{
			Node* tmp = right_node;
			// delete_node의 right_node 중에서 가장 작은 값을 찾아 tmp에 저장한다.
			while (tmp->GetLeftNode() != nullptr)
				tmp = tmp->GetLeftNode();
			
			if (node_delete != root)
				// tmp를 delete_node의 parent Node와 연결시킨다.
				if (parent->GetKey() > node_delete->GetKey())
					parent->SetLeftNode(tmp);
				else
					parent->SetRightNode(tmp);
			// node_delete가 root일 때 예외처리
			else
				root = tmp;
			
			// tmp의 left_node는 현재 없으므로, node_delete의 left_node를 tmp의 left_node로 둔다.
			tmp->SetLeftNode(left_node);

			if (tmp->GetRightNode() != nullptr)
			{
				// delete_node의 right_node를 연결하기 위해, 현재 tmp에서 가장 큰 값을 찾아 tmp에 저장한다.
				while (tmp->GetRightNode() != nullptr)
					tmp = tmp->GetRightNode();
				// tmp의 right_node로 node_delete의 right_node를 둔다.
				tmp->SetRightNode(right_node);
			}
			
			// cf) 크기 관계 : delete_node의 left_node < 가장 작은 값 tmp(parent와 연결한 tmp) < 가장 작은 값 tmp의 right_node < delete_node의 right_node
			// 각각의 left_node와 right_node를 하나의 tree로 묶어서 생각해도 된다.
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
