/*
*	Quest URL : https://billnairk.tistory.com/53
*	�ڿ���

*	���̰� 10�� �迭�� 10���� ������ �Է� ���� ��
	Ȧ���� ¦���� ���� �� �� �ִ� �Լ��� �ΰ� ���� ȣ���� ��
	����غ���.
*/

#include <iostream>
using namespace std;

void OddEven(int* num)
{
	for (int i = 0; i < 10; i++)
	{
		cout << num[i];
		if (num[i] % 2)	// 2�� ������ ��������(¦���̸�)
			cout << " Ȧ��" << endl;
		else
			cout << " ¦��" << endl;
	}
	return;
}

int main(void)
{
	int num[10];
	for (int i = 0; i < 10; i++)
		cin >> num[i];

	OddEven(num);

	return 0;
}