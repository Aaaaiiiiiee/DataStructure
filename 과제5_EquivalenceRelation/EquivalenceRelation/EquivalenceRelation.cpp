/*
*	Equivalence Relation

*	�ڿ���
*/
#include <ctime>
#include "LinkedList.h"
#include <iostream>
using namespace std;

bool** link;	// Use in EquivalenceRelationArray()

void EquivalenceRelationArray();
void dfs(const int& i);

void EquivalenceRelationLinkedList();

int main(void)
{
	clock_t begin, end;

	clock_t by_array;
	begin = clock();
	EquivalenceRelationArray();
	end = clock();
	by_array = end - begin;		// /CLOCKS_PER_SEC ???

	clock_t by_linkedlist;
	begin = clock();
	EquivalenceRelationLinkedList();
	end = clock();
	by_linkedlist = end - begin;

	cout << endl;
	cout << "�ð�(by_array) : " << by_array << endl;
	cout << "�ð�(by_linkedlist) : " << by_linkedlist << endl;
	
	return 0;
}

void EquivalenceRelationArray()
{
	int N;	cin >> N;	// N���� ������ �ִ�.
	link = new bool*[N];	// []�� �����Ҵ� ���ָ� �޸𸮸� �Ҵ��. ()�� �����Ҵ� ���ָ� �迭 ù��° ���� �ش� ������ �ʱ�ȭ�� ��.
	for (int i = 0; i < N; i++)
		link[i] = new bool[N];

	// ���� for��. �Է� ����. ������ ����
	for (int i = 0; i < N; i++)
	{
		int a, b;	cin >> a >> b;
		link[a - 1][b - 1] = link[b - 1][a - 1] = true;	// -1 �� ���ֱ�.
	}

	for (int i = 0; i < N; i++)
		dfs(i);

	for (int i = 0; i < N; i++)
		delete link[i];
	delete[]link;

	return;
}
void dfs(const int& i)
{

}

void EquivalenceRelationLinkedList()
{
	LinkedList linked_list;
	int N;	cin >> N;	// N������ �Է��� ���� ����
	for (int i = 0; i < N; i++)
		linked_list.PushBack(i + 1);
}