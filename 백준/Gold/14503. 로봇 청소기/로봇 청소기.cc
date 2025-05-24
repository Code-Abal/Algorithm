#include<iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int Robot(vector<vector<int>>& arr, vector<vector<bool>>& tf, int r, int c, int d, int N, int M)
{
	queue<pair<int, int>> q;
	q.push({r, c});
	tf[r][c] = true;

	int ans = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		bool full = true;
		for (int i = 0; i < 4; i++)
		{
			d = (d + 3) % 4;

			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx > 0 && ny > 0 && nx < N && ny < M && arr[nx][ny] == 0 && tf[nx][ny] != true)
			{
				q.push({ nx,ny });
				tf[nx][ny] = true;
				full = false;
				ans++;
				break;
			}
		}

		if (full)
		{
			int nx = x - dx[d % 4];
			int ny = y - dy[d % 4];

			if (nx > 0 && ny > 0 && nx < N && ny < M)
			{
				if (arr[nx][ny] == 1)
				{
					break;
				}
				else
				{
					q.push({ nx,ny });
				}
			}
		}
	}

	return ans;
}

int main()
{
	/*
	 $d$가 $0$인 경우 북쪽, $1$인 경우 동쪽, $2$인 경우 남쪽, $3$인 경우 서쪽을 바라보고 있는 것이다.

	 현재 칸의 주변4칸 중 청소되지 않은 빈 칸이 없는 경우,
	 -바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
	 -바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.

	 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
	 반시계 방향으로 90도 회전한다.
	 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.

	*/

	int N, M;
	cin >> N >> M;
	vector<vector<int>> arr(N, vector<int>(M));
	vector<vector<bool>> tf(N, vector<bool>(M, false));
	int r, c, d;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << Robot(arr, tf, r, c, d, N, M);


	return 0;
}