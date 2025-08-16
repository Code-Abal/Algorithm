#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { -1, 0, 1 };
int dy[] = { 1, 1, 1 };

bool pipeLine(vector<vector<char>>& arr, int R, int C, int startX, int startY)
{
	int x = startX;
	int y = startY;
	// 이미 지나간 경로를 표시
	arr[x][y] = 'x'; 

	// 끝에 도달(파이프 연결)시 종료
	if (y == C - 1) 
	{
		return true;
	}

	for (int i = 0; i < 3; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < R && ny < C && arr[nx][ny] != 'x')
		{
			// 연결이 가능하다면, 종료
			// 깊이 우선 탐색이기때문에 지나간 경로를 표시해도 충돌하지 않음
			if (pipeLine(arr, R, C, nx, ny))
			{
				return true;
			}
		}
	}
	return false;
}


int main()
{
	int R, C;
	cin >> R >> C;

	vector<vector<char>> arr(R, vector<char>(C));
	queue<pair<int,int>> start;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> arr[i][j];
			if (j == 0)
			{
				start.push({ i, j });
			}
		}
	}

	int cnt = 0;
	while(!start.empty())
	{
		int x = start.front().first;
		int y = start.front().second;
		start.pop();
		if (pipeLine(arr, R, C, x, y))
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}