/*
*	StringMatching_KMP Algorithm

*	�ڷᱸ�� ����3
*	201811182 �ڿ���
*/
// �� ������ Pattern�� �ִ� ���̸� 100���� ��.
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
		// P[j+1] == P[i] �� ����̸�, �����ؼ� ������ ���ٴ� ���̱� ������, cache[i-1]���� 1 ū ���� �����ϸ� �ȴ�.
		// P[j+1] != P[i]�� ����̸�, j�� �ٸ� ���� ����. �װ��� -1�� ��� Ž���� ������ �� ó�� ���ڿ��� ���ϴ� �Ű�, �� �ٸ� �ε��� ���� �ִ� ��� �ݺ��� ������ �ִ�.

		if (P[i] == P[j + 1])	// ���� ��츦 ���� j���� Ȯ���� ��, j == -1�� ���, �� ó�� ���ڿ��� ������ �񱳸� ���� ������ �� ���ο� ������ ����°Ű�
								// j == (�ٸ� �ε��� ��) �� ��쿡�� ��� ���ӵ� ���ڿ��� �־��ٴ� ���̱� ������, cache[i]�� �ش� ���� �����ϸ鼭, ��� ���ӵ� ������ �����.
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
		cout << e << "��° �ֽ��ϴ�." << endl;

	return 0;
}