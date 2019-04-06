/*
*	미로찾기
*	Quest URL : https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14vXUqAGMCFAYD&categoryId=AV14vXUqAGMCFAYD&categoryType=CODE&&&

*	박원준
*/

#include <stack>
#include <vector>
#include <iostream>
using namespace std;

vector<int> escape;

bool FindExit(const int& idx, char maze[10][16][16])
{
	bool exit = false;
	stack<pair<int, int>> pos;
	// 시작점 index는 [1][1].
	// 0 : 갈 수 있는곳		1 : 갈 수 없는 곳		2 : 시작점		3 : 도착점

	pos.push(pair<int, int>(1, 1));	// 시작점
	while (!pos.empty())
	{
		int i = pos.top().first;
		int j = pos.top().second;
		maze[idx][i][j] = '1';	pos.pop();	// index [i][j]는 이미 방문한 곳. 이제 방문할 수 없는 곳으로 만들어 줌.

											// 왼쪽
		switch (maze[idx][i][j - 1])
		{
		case '0':
			pos.push(pair<int, int>(i, j - 1));
			break;
		case '1': break;
		case '3':
			while (!pos.empty())
				pos.pop();
			exit = true;
			break;
		}
		// 오른쪽
		switch (maze[idx][i][j + 1])
		{
		case '0':
			pos.push(pair<int, int>(i, j + 1));
			break;
		case '1': break;
		case '3':
			while (!pos.empty())
				pos.pop();
			exit = true;
			break;
		}
		// 위
		switch (maze[idx][i - 1][j])
		{
		case '0':
			pos.push(pair<int, int>(i - 1, j));
			break;
		case '1': break;
		case '3':
			while (!pos.empty())
				pos.pop();
			exit = true;
			break;
		}
		// 아래
		switch (maze[idx][i + 1][j])
		{
		case '0':
			pos.push(pair<int, int>(i + 1, j));
			break;
		case '1': break;
		case '3':
			while (!pos.empty())
				pos.pop();
			exit = true;
			break;
		}
	}

	return exit;
}

int main(void)
{
	char maze[10][16][16];
	for (int i = 0; i < 10; i++)
	{
		int tmp;	cin >> tmp;	// TestCase Number;

		for (int j = 0; j < 16; j++)
			for (int k = 0; k < 16; k++)
				cin >> maze[i][j][k];
	}

	for (int i = 0; i < 10; i++)
		FindExit(i, maze) ? escape.push_back(1) : escape.push_back(0);

	for (int i = 0; i < escape.size(); i++)
		cout << "#" << i + 1 << " " << escape[i] << endl;

	return 0;
}