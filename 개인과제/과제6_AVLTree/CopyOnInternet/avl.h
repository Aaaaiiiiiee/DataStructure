#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int data, bf; //bf=balance factor
	Node *leftChild, *rightChild;
	Node(int element, Node *left = 0, Node *right = 0) :data(element), bf(0), leftChild(left), rightChild(right)
	{
	}
};

class AVL
{
private:
	Node * root;
	void Insert(Node *&ptr, int element)
	{
		if (ptr == 0)
			ptr = new Node(element);
		else if (element < ptr->data)
		{
			Insert(ptr->leftChild, element);
			//���� ���ߴ� �ڵ�
			setBF(root);
			if (getBF(ptr) > 1 || getBF(ptr) < -1)
			{
				switch (getBF(ptr))
				{
				case -2: //������ ����Ʈ�� ���̰� ���� ����Ʈ�� ���̺��� 2 ���� ��
					if (getBF(ptr->rightChild) == -1) //������ �ڽ��� bf�� -1�� ��� rr
						ptr = rrRotation(ptr);
					else //������ �ڽ��� bf�� 1�� ��� rl
						ptr = rlRotation(ptr);
					break;
				case 2: //���� ����Ʈ�� ���̰� ������ ����Ʈ������ 2 ���� ��
					if (getBF(ptr->leftChild) == 1) //���� �ڽ��� bf�� 1�� ��� ll
						ptr = llRotation(ptr);
					else //���� �ڽ��� bf�� -1�� ��� lr
						ptr = lrRotation(ptr);
					break;
				}
			}
		}
		else if (element > ptr->data)
		{
			Insert(ptr->rightChild, element);
			setBF(root);
			if (getBF(ptr) > 1 || getBF(ptr) < -1)
			{
				switch (getBF(ptr))
				{
				case -2:
					if (getBF(ptr->rightChild) == -1)
						ptr = rrRotation(ptr);
					else
						ptr = rlRotation(ptr);
					break;
				case 2:
					if (getBF(ptr->leftChild) == 1)
						ptr = llRotation(ptr);
					else
						ptr = lrRotation(ptr);
					break;
				}
			}
		}
		else
			ptr->data = element;
	}
	void Delete(Node *&ptr, int element)
	{
		Node *tmpptr;
		Node *tmpdaddyptr = nullptr;
		if (ptr == 0)
		{
			cout << "�ش� ��带 ã�� �� �����ϴ�" << endl;
			return; //�׷� ��� �����Ƿ� �׳� return
		}
		if (element < ptr->data)
		{
			Delete(ptr->leftChild, element);
			setBF(root);
			if (getBF(ptr) > 1 || getBF(ptr) < -1)
			{
				switch (getBF(ptr))
				{
				case -2:
					if (getBF(ptr->rightChild) == -1)
						ptr = rrRotation(ptr);
					else
						ptr = rlRotation(ptr);
					break;
				case 2:
					if (getBF(ptr->leftChild) == 1)
						ptr = llRotation(ptr);
					else
						ptr = lrRotation(ptr);
					break;
				}
			}
		}
		else if (element > ptr->data)
		{
			Delete(ptr->rightChild, element);
			setBF(root);
			if (getBF(ptr) > 1 || getBF(ptr) < -1)
			{
				switch (getBF(ptr))
				{
				case -2:
					if (getBF(ptr->rightChild) == -1)
						ptr = rrRotation(ptr);
					else
						ptr = rlRotation(ptr);
					break;
				case 2:
					if (getBF(ptr->leftChild) == 1)
						ptr = llRotation(ptr);
					else
						ptr = lrRotation(ptr);
					break;
				}
			}
		}
		else //ptr ��尡 �ٷ� ���� ����� ���
		{
			if (!ptr->leftChild && !ptr->rightChild) //�ڽ��� ���ٸ�
			{
				delete ptr;
				ptr = 0;
				return;
			}
			else if (ptr->leftChild && !ptr->rightChild) //���� �ڽĸ� �ִٸ�
			{
				//�� �ڽ��� ptr�� ����Ű���ϰ� ���� ptr�� ����Ű�� ��� ����
				tmpptr = ptr;
				ptr = ptr->leftChild;
				delete tmpptr;
				return;
			}
			else if (!ptr->leftChild&&ptr->rightChild) //������ �ڽĸ� �ִٸ�
			{
				tmpptr = ptr;
				ptr = ptr->rightChild;
				delete tmpptr;
				return;
			}
			else
			{
				//�� �ڽ� ��� ����:��Ʈ�� rc�� ����Ʈ������ �������� ��� ã��
				Node *rc = ptr->rightChild; //rc�� ��Ʈ�� subtree
				if (!rc->leftChild) //rc�� �����ڽ��� ������ rc�� �� ���
				{
					ptr->data = rc->data;
					ptr->rightChild = rc->rightChild;
					delete rc;
					return;
				}
				//rc�� ���� �ڽ��� �ִ� ���, rc�� ���� �ڽ��� ���� �ڽ��� ������ ���� �ڽ��� ������ �Ѿư�, ���� ���� Ű ���� ��带 ã�´�
				//�� ����� key/element�� ptr���� �ű�� �� ����� rightChild�� �� ����� �θ��� leftChild�� ������ ���� �� ��带 ����
				else
				{
					while (1)
					{
						if (rc->leftChild)
						{
							tmpdaddyptr = rc;
							rc = rc->leftChild;
						}
						else
							break;
					}
					ptr->data = rc->data;
					tmpdaddyptr->leftChild = rc->rightChild;
					delete rc;
					return;
				}
			}
		}
	}
	//ȸ���� �׸����� ����
	Node *llRotation(Node *&ptr)
	{
		Node *temp = ptr->leftChild;
		ptr->leftChild = temp->rightChild;
		temp->rightChild = ptr;
		return temp;
	}
	Node *rrRotation(Node *&ptr)
	{
		Node *temp = ptr->rightChild;
		ptr->rightChild = temp->leftChild;
		temp->leftChild = ptr;
		return temp;
	}
	Node *lrRotation(Node *&ptr)
	{
		Node *temp = ptr->leftChild;
		Node *temp2 = temp->rightChild;
		ptr->leftChild = temp2->rightChild;
		temp2->rightChild = ptr;
		temp->rightChild = temp2->leftChild;
		temp2->leftChild = temp;
		return temp2;
	}
	Node *rlRotation(Node *&ptr)
	{
		Node *temp = ptr->rightChild;
		Node *temp2 = temp->leftChild;
		ptr->rightChild = temp2->leftChild;
		temp2->leftChild = ptr;
		temp->leftChild = temp2->rightChild;
		temp2->rightChild = temp;
		return temp2;
	}
	int getHeight(Node *ptr) //���� ��ȯ
	{
		int height = 0;
		if (ptr != NULL)
		{
			int leftHeight = getHeight(ptr->leftChild);
			int rightHeight = getHeight(ptr->rightChild);
			int result = leftHeight > rightHeight ? leftHeight : rightHeight; //leftHeight�� rightHeight �� ū ���� ��ȯ
			height = result + 1;
		}
		return height;
	}
	int getBF(Node *ptr) //�ش� ����� bf ��ȯ
	{
		return ptr->bf;
	}
	void setBF(Node *ptr) //��� ����� bf�� �ʱ�ȭ
	{
		queue<Node*> q; //ť�� �̿�
		Node *currentNode = ptr;
		while (currentNode)
		{
			int leftHeight = getHeight(currentNode->leftChild);
			int rightHeight = getHeight(currentNode->rightChild);
			currentNode->bf = leftHeight - rightHeight;
			if (currentNode->leftChild)
				q.push(currentNode->leftChild);
			if (currentNode->rightChild)
				q.push(currentNode->rightChild);
			if (q.empty())
				break;
			currentNode = q.front();
			q.pop();
		}
	}
public:
	AVL()
	{
		root = NULL;
		Initialize();
	}
	void Initialize(void) //�ʱ� ����
	{
		Insert(19);
		Insert(10);
		Insert(46);
		Insert(4);
		Insert(14);
		Insert(37);
		Insert(55);
		Insert(7);
		Insert(12);
		Insert(18);
		Insert(28);
		Insert(40);
		Insert(51);
		Insert(61);
		Insert(21);
		Insert(32);
		Insert(49);
		Insert(58);
	}
	void Insert(int element)
	{
		Insert(root, element);
	}
	void Delete(int element)
	{
		Delete(root, element);
	}
	void Search(int element)
	{
		//�������� ��θ� ť�� �����ϰ� ���������� ���
		Node *ptr = root;
		queue<Node*> q;
		bool find = false;
		q.push(ptr);
		if (element == root->data) //root�� �����͸� ã�� ���
		{
			cout << root->data << endl;
			return;
		}
		while (ptr && element != root->data) //root�� �ƴ� ����� �����͸� ã�� ���
		{
			if (element < ptr->data)
			{
				ptr = ptr->leftChild;
				q.push(ptr);
			}
			else if (element > ptr->data)
			{
				ptr = ptr->rightChild;
				q.push(ptr);
			}
			else if (element == ptr->data)
			{
				find = true;
				break;
			}
		}
		if (find)
		{
			while (!q.empty())
			{
				cout << q.front()->data;
				q.pop();
				if (!q.empty())
					cout << " -> ";
			}
			cout << endl;
		}
		else
			cout << "ã���ô� �����Ͱ� �����ϴ�" << endl;
	}
	void Visit(Node *ptr)
	{
		//�ش� ���� �ڽ� ��尡 �����Ѵٸ� �ڽ� ����� �����ͱ��� ���
		cout << ptr->data << " ";
		if (ptr->leftChild)
			cout << "left : " << ptr->leftChild->data << " ";
		if (ptr->rightChild)
			cout << "right: " << ptr->rightChild->data << " ";
		cout << endl;
	}
	//�Ʒ� �ּ����� ó���� �ڵ�� balance factor�� �� ��µǳ� Ȯ���ϱ� ���� �ۼ��� �ڵ�
	/*
	void Visit2(Node *ptr)
	{
	cout << ptr->data<<":"<<ptr->bf << endl;
	}
	void printBF()
	{
	queue<Node *> q;
	Node *currentNode = root;
	while (currentNode)
	{
	Visit2(currentNode);
	if (currentNode->leftChild)
	q.push(currentNode->leftChild);
	if (currentNode->rightChild)
	q.push(currentNode->rightChild);
	if (q.empty())
	break;
	currentNode = q.front();
	q.pop();
	}
	cout << endl;
	}
	*/
	friend ostream &operator<<(ostream &os, AVL &a);
};

ostream &operator<<(ostream &os, AVL &a)
{
	queue<Node*> q;
	Node *currentNode = a.root;
	while (currentNode)
	{
		a.Visit(currentNode);
		if (currentNode->leftChild)
			q.push(currentNode->leftChild);
		if (currentNode->rightChild)
			q.push(currentNode->rightChild);
		if (q.empty())
			break;
		currentNode = q.front();
		q.pop();
	}
	os << endl;
	return os;
}
