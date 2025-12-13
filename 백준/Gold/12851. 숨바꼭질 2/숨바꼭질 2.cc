using namespace std;
#include <iostream>
#include <vector>
#include <queue>

const int MAX_N = 100001;
const int INF = 1e9 + 4;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> predist[MAX_N];
int N, K, ans = 0;
int dist[MAX_N];

void init();
void dijkstra();
void find_dijkstra_path(int node);
void print();

void init()
{
	cin >> N >> K;
	fill(dist, dist + MAX_N, INF);
}

void dijkstra()
{
	dist[N] = 0;
	pq.push({ dist[N], N});

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();

		if (dist[cur.second] != cur.first) continue;

		if (cur.second * 2 < MAX_N && dist[cur.second * 2] >= dist[cur.second] + 1)
		{
			if (dist[cur.second * 2] == dist[cur.second] + 1) 
				predist[cur.second * 2].push_back(cur.second);
			else
			{
				dist[cur.second * 2] = dist[cur.second] + 1;
				pq.push({ dist[cur.second * 2], cur.second * 2 });
				predist[cur.second * 2].clear();
				predist[cur.second * 2].push_back(cur.second);
			}
		}

		if (cur.second - 1 >= 0 && dist[cur.second - 1] >= dist[cur.second] + 1)
		{
			if (dist[cur.second - 1] == dist[cur.second] + 1)
				predist[cur.second - 1].push_back(cur.second);
			else
			{
				dist[cur.second - 1] = dist[cur.second] + 1;
				pq.push({ dist[cur.second - 1], cur.second - 1 });
				predist[cur.second - 1].clear();
				predist[cur.second - 1].push_back(cur.second);
			}
		}
		if (cur.second + 1 < MAX_N && dist[cur.second + 1] >= dist[cur.second] + 1)
		{
			if (dist[cur.second + 1] == dist[cur.second] + 1)
				predist[cur.second + 1].push_back(cur.second);
			else
			{
				dist[cur.second + 1] = dist[cur.second] + 1;
				pq.push({ dist[cur.second + 1], cur.second + 1 });
				predist[cur.second + 1].clear();
				predist[cur.second + 1].push_back(cur.second);
			}
		}
	}
}

// Param(node = target = K)
void find_dijkstra_path(int node)
{
	if (node == N) { ans++; return; }
	for (const auto next : predist[node]) find_dijkstra_path(next);
}

void print()
{
	cout << dist[K] << "\n";
	cout << ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	init();
	dijkstra();
	find_dijkstra_path(K);
	print();

	return 0;
}

