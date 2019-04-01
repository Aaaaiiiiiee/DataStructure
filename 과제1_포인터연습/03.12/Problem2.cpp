/*
*	Quest URL : https://billnairk.tistory.com/53
*	박원준

*	10진수의 정수를 입력 받은 뒤
	2진수로 변환해서 출력해보자.

*	vector : first in last out(스택구조)
*	queue : first in first out(큐구조)
*/

#include <vector>
#include <iostream>
using namespace std;

void BinaryNumber(const int& n, vector<int>* answer)
{
	for (int i = n; true; i /= 2)
	{
		if (i == 0)
		{
			answer->push_back(0);
			break;
		}
		else if (i == 1)
		{
			answer->push_back(1);
			break;
		}
		else
			answer->push_back(i % 2);
	}
}

int main(void)
{
	int n;
	cin >> n;

	vector<int> answer;
	BinaryNumber(n, &answer);
	
	while (!answer.empty())
	{
		cout << answer.back();
		answer.pop_back();
	}
	cout << endl;

	return 0;
}