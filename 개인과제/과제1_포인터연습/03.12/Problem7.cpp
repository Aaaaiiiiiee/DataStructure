/*
*	Quest Url : https://billnairk.tistory.com/44
*	�ڿ���

*	���̰� 5�� int�� �迭�� 1,2,3,4,5�� ���� �� �ʱ�ȭ �� ����
	�迭�� ������ ��Ҹ� ����Ű�� ������ ���� ptr�� ������ ��
	ptr�� ����� ���� ���ҽ�Ű�� ������ ������ �������
	��� �迭 ��ҿ� �����Ͽ�
	�迭�� ����� ��� ������ ���Ͽ� �� ����� ����Ͽ���.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num[] = { 1,2,3,4,5 };

	int sum = 0;
	for (int* ptr = &num[4]; ptr >= &num[0]; ptr--)
		sum += *ptr;
	cout << sum << endl;

	return 0;
}