/*
*	Equivalence Relation

*	�ڿ���
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
	cout << "�ð�(by_array) : " << by_array << endl;
	cout << "�ð�(by_linkedlist) : " << by_linkedlist << endl;
	
	return 0;
}

clock_t EquivalenceRelationArray()
{
	cout << "BY_ARRAY" << endl;
	cin >> N;
	link = new bool*[N];	// []�� �����Ҵ� ���ָ� �޸𸮸� �Ҵ��. ()�� �����Ҵ� ���ָ� �迭 ù��° ���� �ش� ������ �ʱ�ȭ�� ��.
	for (int i = 0; i < N; i++)
	{
		link[i] = new bool[N];
		fill(link[i], link[i] + N, false);
	}

	cache = new bool[N];
	fill(cache, cache + N, false);

	// ���� while��. �Է� ����. ������ ����
	int a, b;
	while(true)
	{
		cin >> a >> b;
		if (a == -1 && b == -1)	break;	// -1 -1 �Է½� �Է� ����.
		link[a][b] = link[b][a] = true;
	}

	clock_t begin, end;
	begin = clock();
	// Ž��.
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

	// ���
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
	// ���� if��. Ż������. �̹� �˻��� ������ ��� �˻����� ����
	if (cache[i])	return;

	bool flag = true;
	// ���� for��. �˻�
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
	cin >> N;	// N������ �Է��� ���� ����
	cache = new bool[N];
	fill(cache, cache + N, false);
	// link 2���� �迭 �ʱ�ȭ.
	linked_list = vector<LinkedList>(N);
	
	
	// ���� while��. ��Ƽ�� ����.
	int a, b;
	while (true)
	{
		cin >> a >> b;
		if (a == -1 && b == -1)	break;
		// linked_list[a][b]�� b���� �����ؾ���. �׷��� b ���� Ÿ�� linked_list[b][?]���� Ž���ϴ°ž�. �װ��� ������� Ž���� �����Ű�.
		linked_list[a].PushBack(b);	linked_list[b].PushBack(a);
	}
	for (int i = 0; i < N; i++)
	{
		linked_list[i].SetCurrentBegin();
		linked_list[i].MoveCurrentToBack();	// �⺻������ current node�� end�� ����Ŵ.
	}

	clock_t begin, end;
	begin = clock();
	// Ž��
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

	// ���
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