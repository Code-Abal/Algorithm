#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 501;
vector<int> graph[MAX_N];
vector<bool> visited(MAX_N);

int dfs()
{
	//pair<next, cnt>
	queue<pair<int, int>> q;
	q.push({ 1, 0 });
    int friends = 0;
	while (!q.empty())
	{
		int node = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		visited[node] = true;

		if (cnt == 2) continue;
		for (auto next : graph[node])
		{
			if (!visited[next])
			{
				q.push({ next, cnt + 1});
				visited[next] = true;
                friends++;
			}
		}
	}
    return friends;
}

int main()
{

	int N, M; cin >> N >> M;
	
	for (int i = 0; i < M; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}

	cout << dfs();
	return 0;
}