/*
*	StringMatching_KMP Algorithm

*	�ڷᱸ�� ����3
*	201811182 �ڿ���
*/
// �� ������ Pattern�� �ִ� ���̸� 100���� ��.
//#include <vector>
#include <string>
#include <iostream>
using namespace std;

string T, P;	// T : Text, P : Pattern
//vector<int> cache;
int cache[100];

//int FailureFunction(const int& idx, const int& num)	// idx : ��ü index ��, i : ���� pattern�� � �־����� �����ϴ� ����, j : ���� ���° ���ϰ� �ִ��� �����ϴ� ����
//{
//	/*int& ref = cache[i];
//	if (i == P.length())	return ref = i - 1;
//
//	if (ref != -1)	return ref;
//	
//	if (P[i] == P[j])
//		return ref = FailureFunction(i + 1, j + 1);
//	else
//		return ref = i;*/
//	if (idx >= P.length())	return num;
//
//	int& ref = cache[idx];
//	if (idx == P.length())	return ref = num;
//
//	if (ref != -1)	return ref;
//
//	for (int k = 0; k < P.length(); k++)
//	{
//		int l = idx + k;
//		if (P[k] == P[l])	continue;
//		
//		return ref = FailureFunction(idx + 1, k);
//	}
//}

void FailureFunction(const int& idx)
{
	if (idx >= P.length())	return;	// Ż������

	int tmp = -1;
	int j;
	for (int i = 0; i < P.length(); i++)
	{
		j = idx + i;
		if (P[i] == P[j])	continue;

		if (cache[j] != -1)
		{
			tmp = j;
			continue;
		}
		else
		{
			cache[idx] = j;
			break;
		}
	}
	if (tmp == -1)
		cache[idx] = j;
	else
		cache[idx] = tmp;

	FailureFunction(idx + 1);
}

int main(void)
{
	fill(cache, cache + 100, -1);	// ��������� Ȯ���غ���. �� -1�� �ʱ�ȭ �ƴ���

	cin >> T >> P;
	//cache[0] = FailureFunction(0, 0);
	FailureFunction(0);

	

	return 0;
}