/*
*	Quest Url : https://billnairk.tistory.com/44
*	�ڿ���

*	Problem5�� �޸� ������ ���� ptr�� ����� ���� �����Ű�� �ʰ�
	ptr�� ������� ���� ������ �Ͽ�
	�迭 ����� ���� 2�� ���� ��Ų �� ����Ͽ���
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num[] = { 1, 2, 3, 4, 5 };
	int* ptr = num;

	for (int i = 0; i < 5; i++)
	{
		*(ptr + i) += 2;
		cout << (*ptr + i) << endl;
	}

	return 0;
}