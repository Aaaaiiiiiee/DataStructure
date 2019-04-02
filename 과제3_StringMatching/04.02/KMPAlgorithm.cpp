/*
*	StringMatching_KMP Algorithm

*	자료구조 과제3
*	201811182 박원준
*/
// 본 문제는 Pattern의 최대 길이를 100으로 둠.
//#include <vector>
#include <string>
#include <iostream>
using namespace std;

string T, P;	// T : Text, P : Pattern
//vector<int> cache;
int cache[100];

//int FailureFunction(const int& idx, const int& num)	// idx : 전체 index 값, i : 같은 pattern이 몇개 있었는지 저장하는 변수, j : 현재 몇번째 비교하고 있는지 저장하는 변수
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
	if (idx >= P.length())	return;	// 탈출조건

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
	fill(cache, cache + 100, -1);	// 디버깅으로 확인해보기. 다 -1로 초기화 됐는지

	cin >> T >> P;
	//cache[0] = FailureFunction(0, 0);
	FailureFunction(0);

	

	return 0;
}