/*
*	Quest URL : https://billnairk.tistory.com/53
*	�ڿ���

*	10������ ������ �Է� ���� ��
	2������ ��ȯ�ؼ� ����غ���.

*	vector : first in last out(���ñ���)
*	queue : first in first out(ť����)
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