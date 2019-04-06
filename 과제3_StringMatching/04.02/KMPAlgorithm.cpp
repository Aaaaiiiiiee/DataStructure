/*
*	StringMatching_KMP Algorithm

*	자료구조 과제3
*	201811182 박원준
*/
// 본 문제는 Pattern의 최대 길이를 100으로 둠.
#include <vector>
#include <string>
#include <iostream>
using namespace std;

string T, P;	// T : Text, P : Pattern
int cache[100];
vector<int> answer;

void FailureFunction()
{
	for (int i = 1; i < P.length(); i++)
	{
		int j = cache[i - 1];
		while (P[j + 1] != P[i] && j >= 0)	j = cache[j];
		// P[j+1] == P[i] 인 경우이면, 연속해서 패턴이 같다는 것이기 때문에, cache[i-1]보다 1 큰 값만 저장하면 된다.
		// P[j+1] != P[i]인 경우이면, j의 다른 곳을 본다. 그곳이 -1일 경우 탐색이 끝나고 맨 처음 문자열을 비교하는 거고, 또 다른 인덱스 값이 있는 경우 반복의 여지가 있다.

		if (P[i] == P[j + 1])	// 위의 경우를 통해 j값이 확정된 후, j == -1인 경우, 맨 처음 문자열이 같은지 비교를 통해 같으면 또 새로운 패턴이 생기는거고
								// j == (다른 인덱스 값) 인 경우에는 어딘가 연속된 문자열이 있었다는 것이기 때문에, cache[i]에 해당 값을 저장하면서, 어딘가 연속된 패턴을 만든다.
			cache[i] = j + 1;
	}
}

void KMPAlgorithm()
{
	/*for (int i = 0; i < T.length(); i++)
	{
		int j;
		for (j = 0; j < P.length(); j++)
		{
			if (T[i] == P[j])	continue;

			if (cache[j] == -1)	break;
			if (!(j = cache[j]))	break;
			
		}

		if (j == P.length())
			answer.push_back(i);
	}*/
	int pos_p = 0, pos_t = 0;
	for (int i = 0; i < T.length(); i++)
	{
		pos_p = 0;
		while (pos_p < P.length() && pos_t < T.length())
		{
			if (P[pos_p] == T[pos_t])
			{
				pos_p++;	pos_t++;
			}
			else
			{
				if (pos_p == 0)
					pos_t++;
				else
					pos_p = cache[pos_p - 1] + 1;
			}
		}
		if (pos_p >= P.length())
			answer.push_back(pos_t - P.length());
	}
}

int main(void)
{
	fill(cache, cache + 100, -1);

	cin >> T >> P;
	
	FailureFunction();
	KMPAlgorithm();

	for (int e : answer)
		cout << e << "번째 있습니다." << endl;

	return 0;
}