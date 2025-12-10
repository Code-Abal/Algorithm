using namespace std;
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
// #define cost first
// #define node second

const int INF = 1e9 + 1004;
const int MAX_N = 1004;

vector<pair<int, int>> graph[MAX_N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> target_to_start_path;

int dist[MAX_N];
int predist[MAX_N];

int N, M, start, target;

void init()
{
	cin >> N >> M;
	fill(dist, dist + MAX_N, INF);
	for (int i = 0; i < M; i++)
	{
		int from, to, cost; cin >> from >> to >> cost;
		graph[from].push_back({ cost, to });
	}
	cin >> start >> target;
}

void dijkstra(int start)
{
	dist[start] = 0;
	// first = cost, second = to(node)
	pq.push({ dist[start], start });

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (dist[cur.second] != cur.first) continue;
		for (const auto& next : graph[cur.second])
		{
			if (dist[next.second] <= dist[cur.second] + next.first) continue;
			dist[next.second] = dist[cur.second] + next.first;
			pq.push({ dist[next.second], next.second });
			predist[next.second] = cur.second;
		}
	}

	int cur_node = target;
	while (cur_node != start)
	{
		target_to_start_path.push_back(cur_node);
		cur_node = predist[cur_node];
	}
	target_to_start_path.push_back(cur_node);
	reverse(target_to_start_path.begin(), target_to_start_path.end());
}

void print()
{
	cout << dist[target] << "\n";
	cout << target_to_start_path.size() << "\n";
	for (auto a : target_to_start_path) cout << a << " ";
}

int main()
{
	init();
	dijkstra(start);
	print();
	return 0;
}

