/*
*	Quest Url : https://billnairk.tistory.com/44
*	박원준

*	길이가 5인 int형 배열을 1,2,3,4,5로 선언 및 초기화 후
	포인터 변수 ptr에 저장된 값을 증가시키는 형태의 연산을 기반으로
	배열 요소에 접근 하면서
	모든 배열 요소의 값을 2씩 증가 시킨 후 출력하여라.
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