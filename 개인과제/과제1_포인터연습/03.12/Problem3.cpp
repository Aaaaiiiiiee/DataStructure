/*
*	Quest Url : https://prosto.tistory.com/253
*	박원준

*	int형 변수를 선언하여 사용자에게 입력 받은 후
	해당 값을 2배로 바꿔주는 함수(반환 형태 : void)를 사용하여
	입력 받은 수의 3배를 출력해주시오.
	(포인터가 인자로 들어간 함수 사용)
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