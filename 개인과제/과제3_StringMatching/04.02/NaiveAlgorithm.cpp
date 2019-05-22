/*
*	StringMatching_Naive Algorithm

*	자료구조 과제3
*	201811182 박원준
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<int> answer;

int main(void)
{
	string T, P;	// T : text 배열, P : pattern 배열
	cin >> T >> P;

	for (int i = 0; i < T.length(); i++)
	{
		int idx = i;
		for (int j = 0; j < P.length();)
		{
			if (T[idx] == P[j])
			{
				idx++;	j++;
				if (j == P.length())
				{
					answer.push_back(i);
					break;
				}
				continue;
			}
			else break;
		}
	}

	int count = 0;
	while (!answer.empty())
	{
		int idx = answer.back();
		answer.pop_back();
		for (int i = 0; i < P.length(); i++)
			cout << T[idx++];
		cout << endl;
		
		count++;
	}
	cout << "총 Pattern의 갯수 : " << count << endl;

	return 0;
}