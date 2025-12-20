#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define distance first
#define node second

const int MAX_N = 801;
const int INF = 1e9;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> graph[MAX_N];
int dist[MAX_N];

int N, M;
int must_node1, must_node2;

void init()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int from, to, cost; 
		cin >> from >> to >> cost;
		graph[from].push_back({ cost, to });
		graph[to].push_back({ cost, from });
	}
	cin >> must_node1 >> must_node2;
}

long long dijkstra(int start, int end)
{
	fill(dist, dist + MAX_N, INF);
	dist[start] = 0;
	pq.push({ dist[start], start });

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (dist[cur.node] != cur.distance) continue;
		for (const auto next : graph[cur.node])
		{
			if (dist[next.node] <= dist[cur.node] + next.distance) continue;

			dist[next.node] = dist[cur.node] + next.distance;
			pq.push({ dist[next.node], next.node });
		}
	}
	return dist[end];
}

void controller()
{
	long long path1 = dijkstra(1, must_node1) + dijkstra(must_node1, must_node2) + dijkstra(must_node2, N);
	long long path2 = dijkstra(1, must_node2) + dijkstra(must_node2, must_node1) + dijkstra(must_node1, N);
	if (path1 >= INF || path2 >= INF) cout << "-1";
	else cout << min(path1, path2);
}

int main()
{
	init();
	controller();
	return 0;
}