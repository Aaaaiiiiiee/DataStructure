/*
*	Quest Url : https://billnairk.tistory.com/44
*	�ڿ���

*	���̰� 5�� int�� �迭�� 1,2,3,4,5�� ���� �� �ʱ�ȭ ��
	������ ���� ptr�� ����� ���� ������Ű�� ������ ������ �������
	�迭 ��ҿ� ���� �ϸ鼭
	��� �迭 ����� ���� 2�� ���� ��Ų �� ����Ͽ���.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num[] = { 1, 2, 3, 4, 5 };
	int* ptr = num;

	/*for (int i = 0; i < 5; i++)
	{
		*ptr += 2;
		cout << *ptr << endl;
		ptr++;
	}*/

	for (int* ptr = num; ptr <= &num[4]; ptr++)
	{
		*ptr += 2;
		cout << *ptr << endl;
	}

	return 0;
}