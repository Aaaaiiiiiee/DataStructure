/*
*	Quest Url : https://prosto.tistory.com/253
*	박원준

*	숫자1, 숫자2 두 개의 숫자를 입력 받아
	포인터 두 개의 인자를 받는 함수로
	두 숫자를 바꾼 후 출력해주는 프로그램을 만드세요
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

	cout << "바꾸기 전 : " << num1 << " " << num2 << endl;
	Swap(&num1, &num2);
	cout << "바꾼 후 : " << num1 << " " << num2 << endl;

	return 0;
}