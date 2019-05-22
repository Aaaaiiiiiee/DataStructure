/*
*   Quest URL : https://www.swexpertacademy.com/main/code/userProblem/userProblemDetail.do?contestProbId=AWrb3KxKMHQDFARG&categoryId=AWrb3KxKMHQDFARG&categoryType=CODE
*   201811182 박원준
*/
#include "BinarySearchTree.h"

int N;  // 전체 명령 개수
BinarySearchTree bst;

void Insert();  // insert 명령
bool DownTree();    // Down Tree 명령

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