#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX_INT INT32_MAX

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
const int MAX_N = 100;

int map[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];

int T;

int bfs(int map[][MAX_N], int N)
{
	fill(&dist[0][0], &dist[MAX_N - 1][MAX_N], MAX_INT);

	queue<pair<int, int>> q;

	dist[0][0] = 0;
	q.push({ 0,0 });

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < N)
			{
				int current = dist[cur.first][cur.second] + map[nx][ny];
				if (current < dist[nx][ny])
				{
					dist[nx][ny] = current;
					q.push({ nx, ny });
				}
			}
		}
	}
	return dist[N - 1][N - 1];
}

void run()
{
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;

		fill(&map[0][0], &map[MAX_N - 1][MAX_N], 0);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				char c;	cin >> c;
				map[i][j] = c - '0';
			}
		}
		int ans = bfs(map, N);
		cout << "#" << test_case << " " << ans << "\n";
	}
}

int main()
{
	run();
	return 0;
}