#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//<코어활성화, 전선길이>
vector<pair<int, int>> ans;
static int maxConnect = 0;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

bool canConnect(vector<vector<int>>& arr, vector<vector<bool>>& visited,
	int N, int x, int y, int dir)
{
	int nx = x;
	int ny = y;

	while (1)
	{
		nx += dx[dir];
		ny += dy[dir];

		// 끝에 도달했다면 = 연결가능
		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
		{
			return true;
		}

		// 연결중간에 코어가 있거나 전선이 있거나(방문했거나)
		if (arr[nx][ny] == 1 || visited[nx][ny])
		{
			return false;
		}
	}
}

int setConnect(vector<vector<int>>& arr, vector<vector<bool>>& visited,
	int N, int x, int y, int dir)
{
	int nx = x;
	int ny = y;
	visited[nx][ny] = true;

	int wire = 0;
	while (1)
	{
		nx += dx[dir];
		ny += dy[dir];

		//끝에 도달했다면, 전선길이 던짐
		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
		{
			return wire;
		}
		visited[nx][ny] = true;
		wire++;
	}
}

void revokeConnect(vector<vector<int>>& arr, vector<vector<bool>>& visited,
	int N, int x, int y, int dir)
{
	int nx = x;
	int ny = y;
	visited[nx][ny] = false;

	while (1)
	{
		nx += dx[dir];
		ny += dy[dir];

		//방문을 초기화하며, 끝까지 초기화했다면 종료
		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
		{
			return;
		}
		visited[nx][ny] = false;
	}
}

void Process(vector<vector<int>>& arr, vector<vector<bool>>& visited,
	vector<pair<int, int>>& core, int N, int coreIdx, int connected, int dist)
{
	if (coreIdx == core.size())
	{
		if (connected >= maxConnect)
		{
			maxConnect = max(maxConnect, connected);
			ans.push_back({ maxConnect, dist });
		}
		return;
	}

	int x = core[coreIdx].first;
	int y = core[coreIdx].second;

	Process(arr, visited, core, N, coreIdx + 1, connected, dist);
	for (int dir = 0; dir < 4; dir++)
	{
		//연결가능
		if (canConnect(arr, visited, N, x, y, dir))
		{
			// 연결시도
			int wire = setConnect(arr, visited, N, x, y, dir);
			// 연결
			Process(arr, visited, core, N, coreIdx + 1, connected + 1, dist + wire);

			revokeConnect(arr, visited, N, x, y, dir);
		}
	}
}

int main()
{
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int N; cin >> N;

		vector<vector<int>> arr (N, vector<int>(N));
		vector<vector<bool>> visited(N, vector<bool>(N));
		vector<pair<int, int>> core;
		maxConnect = 0;
		core.clear();
		ans.clear();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == 1)
				{
					if (i != 0 && i != N - 1 && j != 0 && j != N - 1)
					{
						core.push_back({ i, j });
					}
				}
			}
		}
		Process(arr, visited, core, N, 0, 0, 0);

		sort(ans.begin(), ans.end(), [](const pair<int,int> a, const pair<int,int> b)
		{
			if (a.first == b.first)
			{
				return a.second < b.second;
			}
			return a.first > b.first;
		});
		cout << "#" << tc << " " << ans[0].second << "\n";
	}
	return 0;
}