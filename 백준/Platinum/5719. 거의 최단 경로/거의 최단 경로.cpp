using namespace std;
#include <iostream>
#include <queue>
#include <vector>

const int INF = 1e9 + 1004;
const int MAX_N = 504;

vector<pair<int, int>> graph[MAX_N];
vector<int> predist[MAX_N];
int visited_remove[MAX_N];
int dist[MAX_N];

int N, M, start, target;

int init();
void dijkstra(int start);
void remove_dijkstra_path(int node);
void print();
void remove_path();

int init()
{
	cin >> N >> M;
	if (N == 0 && M == 0) return 0;
	cin >> start >> target;

	for (int i = 0; i < MAX_N; i++) { graph[i].clear(); predist[i].clear(); }

	for (int i = 0; i < M; i++)
	{
		int from, to, cost; cin >> from >> to >> cost;
		graph[from].push_back({ cost, to });
	}
	return 1;
}

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	fill(dist, dist + MAX_N, INF);
	dist[start] = 0;

	pq.push({ dist[start], start });

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (dist[cur.second] != cur.first) continue;
		for (const auto& next : graph[cur.second])
		{
			if (dist[next.second] > dist[cur.second] + next.first)
			{
				dist[next.second] = dist[cur.second] + next.first;
				pq.push({ dist[next.second], next.second });
				predist[next.second].clear();
				predist[next.second].push_back(cur.second);
			}
			else if (dist[next.second] == dist[cur.second] + next.first)
				predist[next.second].push_back(cur.second);
		}
	}
}

void remove_dijkstra_path(int node)
{
	if (node == start) return;
	if (visited_remove[node]) return;

	visited_remove[node] = true;

	for (int next : predist[node])
	{
		for (int idx = 0; idx < graph[next].size(); idx++)
		{
			if (graph[next][idx].second == node)
			{
				graph[next].erase(graph[next].begin() + idx);
				break;
			}
		}
		remove_dijkstra_path(next);
	}
}

void remove_path()
{
	fill(visited_remove, visited_remove + MAX_N, false);
	remove_dijkstra_path(target);
}

void print()
{
	if (dist[target] == INF) cout << "-1\n";
	else cout << dist[target] << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (init())
	{
		dijkstra(start);
		if (dist[target] == INF) print();
		else { remove_path(); dijkstra(start); print(); }
	}
	return 0;
}

