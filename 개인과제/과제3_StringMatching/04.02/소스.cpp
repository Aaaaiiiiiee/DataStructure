#include <string>
#include <vector>
#include <iostream>
using namespace std;

string T, P;	// T : text, P : pattern

vector<int> FailureFunction()
{
	int pattern_size = P.size();
	vector<int> table(pattern_size, 0);
	int j = 0;
	for (int i = 1; i < pattern_size; i++)
	{
		while (j > 0 && P[i] != P[j])	// j가 0이면, 탐색할 필요가 없음.
			j = table[j - 1];

		if (P[i] == P[j])
			table[i] = ++j;
	}
	return table;
}

int main(void)
{
	cin >> T >> P;
	vector<int> table = FailureFunction();

	int j = 0;
	for (int i = 0; i < T.size(); i++)
	{
		while (j > 0 && T[i] != P[j])
			j = table[j - 1];

		if (T[i] == P[j])
			if (j == P.size() - 1)
			{
				cout << i - P.size() + 2 << "번째에서 찾았습니다." << endl;
				j = table[j];
			}
			else
				j++;
	}

	return 0;
}