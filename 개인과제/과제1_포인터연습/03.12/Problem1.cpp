/*
*	Quest URL : https://billnairk.tistory.com/53
*	박원준

*	길이가 10인 배열에 10개의 정수를 입력 받은 뒤
	홀수와 짝수를 구분 할 수 있는 함수를 두개 만들어서 호출한 뒤
	출력해보자.
*/

#include <iostream>
using namespace std;

void OddEven(int* num)
{
	for (int i = 0; i < 10; i++)
	{
		cout << num[i];
		if (num[i] % 2)	// 2로 나누어 떨어지면(짝수이면)
			cout << " 홀수" << endl;
		else
			cout << " 짝수" << endl;
	}
	return;
}

int main(void)
{
	int num[10];
	for (int i = 0; i < 10; i++)
		cin >> num[i];

	OddEven(num);

	return 0;
}