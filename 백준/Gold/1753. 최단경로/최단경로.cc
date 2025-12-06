#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define cost first
#define node second

// pair<int,int> {비용, 노드} 
vector<pair<int, int>> graph[20001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

const int MAX_V = 20000;
const int INF = 1e9;

int dist[20001];
int V, E, start;

void init()
{
	cin >> V >> E >> start;

	fill(dist, dist + V + 1, INF);
	
	for (int i = 0; i < E; i++)
	{
		int from, to, cost; cin >> from >> to >> cost;
		graph[from].push_back({cost, to});
	}
}

void dijkstra(int start)
{
	dist[start] = 0;
	// {비용, 시작 노드}
	pq.push({ dist[start], start });

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (dist[cur.node] != cur.cost) continue;
		for (const auto& next : graph[cur.node]) 
		{
			if (dist[next.node] <= dist[cur.node] + next.cost) continue;
			dist[next.node] = dist[cur.node] + next.cost;
			pq.push({ dist[next.node], next.node });
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	dijkstra(start);
	return 0;
}