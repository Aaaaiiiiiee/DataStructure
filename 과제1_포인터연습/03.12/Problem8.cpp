/*
*	Quest Url : https://billnairk.tistory.com/44
*	박원준

*	길이가 6인 int형 배열에 1,2,3,4,5,6을 선언 및 초기화 한 다음
	배열에 저장된 값의 순서가 6,5,4,3,2,1이 되도록 출력하여라.
	단, 배열의 앞과 뒤를 가리키는 포인터 변수를 두개를 이용해야한다.
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