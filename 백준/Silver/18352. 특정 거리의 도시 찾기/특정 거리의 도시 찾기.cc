#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static int citycnt = 0;
vector<int> graph[300001];
vector<int> ans;
void find( vector<bool>& visited, int start, int depth)
{
	queue<vector<int>> q;
	q.push({ start, 0 });
	visited[start] = true;
	while (!q.empty())
	{
		vector<int> info = q.front();
		int current = info[0];
		int cnt = info[1];
		q.pop();

		if (cnt == depth)
		{
			ans.push_back(current);
			citycnt++;
		}

		for (auto a : graph[current])
		{
			if (!visited[a])
			{
				q.push({ a, cnt + 1 });
				visited[a] = true;
			}
		}
	}
}

int main()
{
	int N, M, K, X;
	cin >> N >> M >> K >> X;

	vector<bool> visited(N + 1);

	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
	}

	find(visited, X, K);
	sort(ans.begin(), ans.end());
	if (citycnt == 0) cout << "-1";
	else
	{
		for (auto a : ans)
		{
			cout << a << "\n";
		}
	}
	return 0;
}