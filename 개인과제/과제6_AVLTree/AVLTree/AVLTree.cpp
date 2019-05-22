/*
*	�Ǳ����б� �������� ����Ʈ�����а�
*	�ڷᱸ�� �輺�� ������
*	201811182 �ڿ���

*	����6
*	AVL Tree ����
*/
#include <iostream>
using namespace std;

class Node
{
private : 
	Node* up_node;
	Node* left_node;
	Node* right_node;
	int height_left;
	int height_right;

	int* key;
public : 
	Node() : up_node(root), left_node(nullptr), right_node(nullptr), key(nullptr) {}	// ������ Node �����(�ʱ� root ���� ��)
	Node(int x) : up_node(this), left_node(new Node()), right_node(new Node()), key(new int(x)), height_left(0), height_right(0) {}	//(root ���� ��)

	Node* GetUpNode() { return up_node; }
	Node * GetLeftNode() { return left_node; }
	Node* GetRightNode() { return right_node; }
	int GetHeightLeft() { return height_left; }
	int GetHightRight() { return height_right; }
	int* GetKey() { return key; }
	int* SetKey(int x) { *(this->key) = x; }
};
class AVLTree
{
private : 
	Node * root;

public : 
	AVLTree(int x) : root(new Node(x)) {}

	/* ã�� �� x�� �ּҰ� ��ȯ */
	Node* Search(int x)
	{
		Node* next = root;
		//Node* tmp;
		while (next->GetKey() != nullptr)
		{
			if (x > *(next->GetKey()))
			{
				//tmp = next;
				next = next->GetRightNode();
			}
			else if (x < *(next->GetKey()))
			{
				//tmp = next;
				next = next->GetLeftNode();
			}
			else
				break;
		}
		return next;
		//return tmp;
	}
	/* x�� key������ �ϴ� ���ο� Node ���� */
	void Insert(int x)
	{
		Node* search_result = Search(x);
		if (search_result->GetKey() == nullptr)	// x�� ���� tree�� ����� ����
		{
			search_result->SetKey(x);

		}
	}
	/* x�� key������ �ϴ� Node�� ���� */
	void Delete(int x)
	{
		Node* search_result = Search(x);
		if (search_result->GetKey() != nullptr)
		{

		}
	}
};

int main(void)
{

	return 0;
}