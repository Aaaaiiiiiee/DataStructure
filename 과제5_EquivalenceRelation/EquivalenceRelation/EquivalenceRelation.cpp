/*
*	Equivalence Relation

*	박원준
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
	cout << "시간(by_array) : " << by_array << endl;
	cout << "시간(by_linkedlist) : " << by_linkedlist << endl;
	
	return 0;
}

void EquivalenceRelationArray()
{
	int N;	cin >> N;	// N개의 집합이 있다.
	link = new bool*[N];	// []로 동적할당 해주면 메모리만 할당됨. ()로 동적할당 해주면 배열 첫번째 방이 해당 값으로 초기화도 됨.
	for (int i = 0; i < N; i++)
		link[i] = new bool[N];

	// 하위 for문. 입력 받음. 집합의 연결
	for (int i = 0; i < N; i++)
	{
		int a, b;	cin >> a >> b;
		link[a - 1][b - 1] = link[b - 1][a - 1] = true;	// -1 꼭 해주기.
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
	int N;	cin >> N;	// N가지의 입력을 받을 것임
	for (int i = 0; i < N; i++)
		linked_list.PushBack(i + 1);
}