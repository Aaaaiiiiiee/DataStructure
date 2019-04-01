/*
*	Quest Url : https://billnairk.tistory.com/44
*	박원준

*	길이가 5인 int형 배열에 1,2,3,4,5를 선언 및 초기화 한 다음
	배열의 마지막 요소를 가리키는 포인터 변수 ptr을 선언한 후
	ptr에 저장된 값을 감소시키는 형태의 연산을 기반으로
	모든 배열 요소에 접근하여
	배열에 저장된 모든 정수를 더하여 그 결과를 출력하여라.
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