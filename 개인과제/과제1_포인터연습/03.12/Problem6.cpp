/*
*	Quest Url : https://billnairk.tistory.com/44
*	박원준

*	Problem5와 달리 포인터 변수 ptr에 저장된 값을 변경시키지 않고
	ptr을 대상으로 덧셈 연산을 하여
	배열 요소의 값을 2씩 증가 시킨 후 출력하여라
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