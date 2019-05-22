/*
*	건국대학교 공과대학 소프트웨어학과
*	자료구조 김성열 교수님
*	201811182 박원준

*	과제6
*	AVL Tree 구현
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
	Node() : up_node(root), left_node(nullptr), right_node(nullptr), key(nullptr) {}	// 쓰레기 Node 만들기(초기 root 생성 중)
	Node(int x) : up_node(this), left_node(new Node()), right_node(new Node()), key(new int(x)), height_left(0), height_right(0) {}	//(root 생성 중)

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

	/* 찾는 값 x의 주소값 반환 */
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
	/* x를 key값으로 하는 새로운 Node 삽입 */
	void Insert(int x)
	{
		Node* search_result = Search(x);
		if (search_result->GetKey() == nullptr)	// x가 현재 tree에 없어야 대입
		{
			search_result->SetKey(x);

		}
	}
	/* x를 key값으로 하는 Node를 삭제 */
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