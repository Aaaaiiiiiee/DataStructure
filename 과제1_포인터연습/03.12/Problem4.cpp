/*
*	Quest Url : https://prosto.tistory.com/253
*	�ڿ���

*	����1, ����2 �� ���� ���ڸ� �Է� �޾�
	������ �� ���� ���ڸ� �޴� �Լ���
	�� ���ڸ� �ٲ� �� ������ִ� ���α׷��� ���弼��
*/

#include <iostream>
using namespace std;

void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	return;
}

int main(void)
{
	int num1, num2;
	cin >> num1 >> num2;

	cout << "�ٲٱ� �� : " << num1 << " " << num2 << endl;
	Swap(&num1, &num2);
	cout << "�ٲ� �� : " << num1 << " " << num2 << endl;

	return 0;
}