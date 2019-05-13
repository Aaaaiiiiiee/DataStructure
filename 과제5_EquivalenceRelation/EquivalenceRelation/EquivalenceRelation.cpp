/*
*	Equivalence Relation

*	박원준
*/
#include <vector>
#include <stack>
#include <ctime>
#include "LinkedList.h"
#include <iostream>
using namespace std;

int N;						// Number of Set. Use like const number in code.
bool** link;				// Use in EquivalenceRelationArray()
vector<LinkedList> linked_list(N);	// Use in EquivalenceRelationLinkedList()

bool* cache;				// Use in EquivalenceRelationArray() & EquivalenceRelationLinkedList()
vector<int> part;			// Use in EquivalenceRElationArray() & EquivalenceRelationLinkedList()
stack<int> partition_array;	// Use in EquivalenceRElationArray() & EquivalenceRelationLinkedList()
vector<vector<int>> answer;	// Use in EquivalenceRElationArray() & EquivalenceRelationLinkedList()

clock_t EquivalenceRelationArray();
void dfs(const int& i);

clock_t EquivalenceRelationLinkedList();
void dfs_LinkedList(const int& i);

void Print();

int main(void)
{
	clock_t by_array = EquivalenceRelationArray();
	//by_array /= CLOCKS_PER_SEC;
	by_array /= (double)1000;
	
	clock_t by_linkedlist = EquivalenceRelationLinkedList();
	//by_linkedlist /= CLOCKS_PER_SEC;
	by_linkedlist /= (double)1000;

	cout << endl;
	cout << "시간(by_array) : " << by_array << endl;
	cout << "시간(by_linkedlist) : " << by_linkedlist << endl;
	
	return 0;
}

clock_t EquivalenceRelationArray()
{
	cout << "BY_ARRAY" << endl;
	cin >> N;
	link = new bool*[N];	// []로 동적할당 해주면 메모리만 할당됨. ()로 동적할당 해주면 배열 첫번째 방이 해당 값으로 초기화도 됨.
	for (int i = 0; i < N; i++)
	{
		link[i] = new bool[N];
		fill(link[i], link[i] + N, false);
	}

	cache = new bool[N];
	fill(cache, cache + N, false);

	// 하위 while문. 입력 받음. 집합의 연결
	int a, b;
	while(true)
	{
		cin >> a >> b;
		if (a == -1 && b == -1)	break;	// -1 -1 입력시 입력 종료.
		link[a][b] = link[b][a] = true;
	}

	clock_t begin, end;
	begin = clock();
	// 탐색.
	for (int i = 0; i < N; i++)
	{
		dfs(i);

		while (!partition_array.empty())
		{
			part.push_back(partition_array.top());
			partition_array.pop();
		}

		if (!part.empty())
		{
			answer.push_back(part);
			part.clear();
		}
	}
	end = clock();

	// 출력
	Print();

	answer.clear();
	for (int i = 0; i < N; i++)
		delete link[i];
	delete[]link;
	delete[]cache;

	return end - begin;
}
void dfs(const int& i)
{
	// 하위 if문. 탈출조건. 이미 검사한 구간일 경우 검사하지 않음
	if (cache[i])	return;

	bool flag = true;
	// 하위 for문. 검사
	for (int j = 0; j < N; j++)
	{
		if (link[i][j])
		{
			if (cache[j])	continue;
			cache[i] = true;
			dfs(j);
			if (flag)
			{
				partition_array.push(i);
				flag = false;
			}
		}
	}
	if (!cache[i])
	{
		partition_array.push(i);
		cache[i] = true;
	}
	return;
}

clock_t EquivalenceRelationLinkedList()
{
	cout << "BY_LINKEDLIST" << endl;
	cin >> N;	// N가지의 입력을 받을 것임
	cache = new bool[N];
	fill(cache, cache + N, false);
	// link 2차원 배열 초기화.
	linked_list = vector<LinkedList>(N);
	
	
	// 하위 while문. 파티션 생성.
	int a, b;
	while (true)
	{
		cin >> a >> b;
		if (a == -1 && b == -1)	break;
		// linked_list[a][b]에 b값을 저장해야지. 그래서 b 값을 타고 linked_list[b][?]값에 탐색하는거야. 그곳이 비었으면 탐색이 끝난거고.
		linked_list[a].PushBack(b);	linked_list[b].PushBack(a);
	}
	for (int i = 0; i < N; i++)
	{
		linked_list[i].SetCurrentBegin();
		linked_list[i].MoveCurrentToBack();	// 기본적으로 current node는 end를 가리킴.
	}

	clock_t begin, end;
	begin = clock();
	// 탐색
	for (int i = 0; i < N; i++)
	{
		dfs_LinkedList(i);

		while (!partition_array.empty())
		{
			part.push_back(partition_array.top());
			partition_array.pop();
		}

		if (!part.empty())
		{
			answer.push_back(part);
			part.clear();
		}
	}
	end = clock();

	// 출력
	Print();

	answer.clear();
	delete[]cache;

	return end - begin;
}
void dfs_LinkedList(const int& i)
{
	if (cache[i])	return;
	
	bool flag = true;
	while (linked_list[i].GetCurrent() != linked_list[i].GetEnd())
	{
		int j = linked_list[i].GetCurrent()->GetKey();

		if (cache[j])
		{
			linked_list[i].MoveCurrentToBack();
			continue;
		}
		cache[i] = true;

		dfs_LinkedList(j);

		if (flag)
		{
			partition_array.push(i);
			flag = false;
		}

		linked_list[i].MoveCurrentToBack();
	}
	if (!cache[i])
	{
		partition_array.push(i);
		cache[i] = true;
	}
	return;
}

void Print()
{
	cout << endl << "Set A = " << endl;
	for (int i = 0; i < answer.size(); i++)
	{
		cout << "A" << i + 1 << " : ";
		for (int j = 0; j < answer[i].size(); j++)
			cout << answer[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}