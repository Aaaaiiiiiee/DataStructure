/*
*	Quest Url : https://billnairk.tistory.com/44
*	�ڿ���

*	���̰� 6�� int�� �迭�� 1,2,3,4,5,6�� ���� �� �ʱ�ȭ �� ����
	�迭�� ����� ���� ������ 6,5,4,3,2,1�� �ǵ��� ����Ͽ���.
	��, �迭�� �հ� �ڸ� ����Ű�� ������ ������ �ΰ��� �̿��ؾ��Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num[6] = { 1,2,3,4,5,6 };
	int* ptr1 = &num[0], *ptr2 = &num[5];

	for (int e : num)
		cout << e << " ";
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		int temp = *(ptr1 + i);
		*(ptr1 + i) = *(ptr2 - i);
		*(ptr2 - i) = temp;
	}
	for (int e : num)
		cout << e << " ";
	cout << endl;

	return 0;
}