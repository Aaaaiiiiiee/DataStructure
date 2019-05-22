/*
*   Quest URL : https://www.swexpertacademy.com/main/code/userProblem/userProblemDetail.do?contestProbId=AWrb3KxKMHQDFARG&categoryId=AWrb3KxKMHQDFARG&categoryType=CODE
*   201811182 �ڿ���
*/
#include "BinarySearchTree.h"

int N;  // ��ü ��� ����
BinarySearchTree bst;

void Insert();  // insert ���
bool DownTree();    // Down Tree ���

int main(void)
{
	int count_false = 0;

	cin >> N;
	while (N--)
	{
		char ch;    cin >> ch;
		switch (ch)
		{
		case 'i': Insert();
			break;
		case 's':
			if (!DownTree())    count_false++;
			break;
		}
	}

	cout << "#1 " << count_false << endl;

	return 0;
}

void Insert()
{
	int key;    cin >> key;
	bst.Push(key);
	return;
}

bool DownTree()
{
	string sequence;    cin >> sequence;
	return bst.DownTree(sequence);
}