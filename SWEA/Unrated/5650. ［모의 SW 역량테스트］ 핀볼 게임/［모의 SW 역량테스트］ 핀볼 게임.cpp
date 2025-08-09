#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<pair<int, int>> whole6, whole7, whole8, whole9, whole10;
queue<vector<int>> ballq;
pair<int, int> whole(int holenum, int x, int y)
{
	if (holenum == 6)
	{
		if (x == whole6[0].first && y == whole6[0].second) return whole6[1];
		else return whole6[0];
	}
	else if (holenum == 7)
	{
		if (x == whole7[0].first && y == whole7[0].second) return whole7[1];
		else return whole7[0];
		
	}
	else if (holenum == 8)
	{
		if (x == whole8[0].first && y == whole8[0].second) return whole8[1];
		else return whole8[0];
	}
	else if (holenum == 9)
	{
		if (x == whole9[0].first && y == whole9[0].second) return whole9[1];
		else return whole9[0];
	}
	else if (holenum == 10)
	{
		if (x == whole10[0].first && y == whole10[0].second) return whole10[1];
		else return whole10[0];
	}
}

void setwhole(int holenum, int i, int j)
{
	if (holenum == 6)
	{
		whole6.push_back({ i, j });
	}
	else if (holenum == 7)
	{
		whole7.push_back({ i, j });
	}
	else if (holenum == 8)
	{
		whole8.push_back({ i, j });
	}
	else if (holenum == 9)
	{
		whole9.push_back({ i, j });
	}
	else if (holenum == 10)
	{
		whole10.push_back({ i, j });
	}
}

int direction(int angle, int dir)
{
	if (angle == 1)
	{
		if (dir == 0)dir = 2;
		else if (dir == 1)dir = 3;
		else if (dir == 2)dir = 1;
		else if (dir == 3)dir = 0;
	}
	else if (angle == 2)
	{
		if (dir == 0)dir = 1;
		else if (dir == 1)dir = 3;
		else if (dir == 2)dir = 0;
		else if (dir == 3)dir = 2;
	}
	else if (angle == 3)
	{
		if (dir == 0)dir = 3;
		else if (dir == 1)dir = 2;
		else if (dir == 2)dir = 0;
		else if (dir == 3)dir = 1;
	}
	else if (angle == 4)
	{
		if (dir == 0)dir = 2;
		else if (dir == 1)dir = 0;
		else if (dir == 2)dir = 3;
		else if (dir == 3)dir = 1;
	}
	else if (angle == 5)
	{
		if (dir == 0)dir = 2;
		else if (dir == 1)dir = 3;
		else if (dir == 2)dir = 0;
		else if (dir == 3)dir = 1;
	}
	return dir;
}

int pinball(vector<vector<int>>& arr, int start_i, int start_j, int d, int N)
{
	
	int x = start_i;
	int y = start_j;

	int cnt = 0;
	int dir = d;
	while (1)
	{
		if (cnt > N * N * 4) return 0;

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		//cout << nx << " " << ny << "\n";
		if (nx >= 0 && ny >= 0 && nx < N && ny < N)
		{
			if (arr[nx][ny] == -1) return cnt;
			else if (nx == start_i && ny == start_j) return cnt;
			else if (arr[nx][ny] == 0) x = nx, y = ny;
			else if (1 <= arr[nx][ny] && arr[nx][ny] <= 5)
			{
				int ndir = direction(arr[nx][ny], dir);
				dir = ndir;
				x = nx; y = ny;
				cnt++;
			}
			else if (6 <= arr[nx][ny] && arr[nx][ny] <= 10) // 웜홀
			{
				pair<int, int> pos = whole(arr[nx][ny], nx, ny);
				x = pos.first, y = pos.second;
			}
		}

	}
	return 0;
}
int main()
{
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int N; cin >> N;

		vector<vector<int>> arr(N + 2, vector<int>(N + 2, 5));
		queue<vector<int>> q;
		whole6.clear(); whole7.clear(); whole8.clear(); whole9.clear(); whole10.clear();
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == 0)
				{
					for (int dir = 0; dir < 4; dir++)
					{
						// x, y, cnt, dir
						q.push({ i, j, dir });

					}
				}
				else if (6 <= arr[i][j] && arr[i][j] <= 10)
				{
					setwhole(arr[i][j], i, j);
				}
			}
		}

		int maxcnt = 0;
		while (!q.empty())
		{
			vector<int> info = q.front();
			int i = info[0];
			int j = info[1];
			int dir = info[2];
			q.pop();
			int cnt = pinball(arr, i, j, dir, N + 2);
			maxcnt = max(maxcnt, cnt);
		}
		cout << "#" << tc << " " << maxcnt << "\n";
	}
	return 0;
}