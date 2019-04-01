#include <ctime>
#include <algorithm>
#include <iostream>
using namespace std;
#define LENGTH 5

int A[] = { 1,2,3,4,5 };

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int A[], const int& i, const int& j)
{
	if (j - 1 < i)
		return;
	else
	{
		if (A[j] < A[j - 1])
			Swap(A[j], A[j - 1]);
		
		BubbleSort(A, i, j - 1);
	}
}

int main(void)
{
	srand(time(NULL));

	random_shuffle(A, A + 4);
	for (int e : A)
		cout << e << " ";
	cout << endl;

	for (int i = 0; i < LENGTH; i++)
		BubbleSort(A, i, LENGTH - 1);

	for (int e : A)
		cout << e << " ";
	cout << endl;

	return 0;
}