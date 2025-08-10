#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int cnt = 0;

void powerSet(vector<bool>& visited, vector<int>* food, int idx, int N, int M, int select)
{
	if (idx > 1)
	{
		for (int i = 1; i < idx; i++)
		{
			if (!visited[i]) continue;
			for (auto f : food[i])
			{
				if (visited[i] && visited[f]) return;
			}
		}
	}

	if (idx == N + 1)
	{
		if (select < 2)cnt++;
		else cnt++;
		return;
	}
	
	visited[idx] = true;
	powerSet(visited, food, idx + 1, N, M, select + 1);

	visited[idx] = false;
	powerSet(visited, food, idx + 1, N, M, select);
}

int main()
{
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int N, M; cin >> N >> M;
		vector<int> food[21];
		cnt = 0;
		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			food[a].push_back(b);
		}
		vector<bool>visited(N + 1, false);
		powerSet(visited, food, 1, N, M, 0);
		cout << "#" << tc << " " << cnt << "\n";
	}
	return 0;
}