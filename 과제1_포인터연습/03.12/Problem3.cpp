/*
*	Quest Url : https://prosto.tistory.com/253
*	�ڿ���

*	int�� ������ �����Ͽ� ����ڿ��� �Է� ���� ��
	�ش� ���� 2��� �ٲ��ִ� �Լ�(��ȯ ���� : void)�� ����Ͽ�
	�Է� ���� ���� 3�踦 ������ֽÿ�.
	(�����Ͱ� ���ڷ� �� �Լ� ���)
*/

#include <iostream>
using namespace std;

void Multiply3(int* num)
{
	cout << 3 * (*num) << endl;
	return;
}

int main(void)
{
	int num;
	cin >> num;

	Multiply3(&num);

	return 0;
}