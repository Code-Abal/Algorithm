using namespace std;
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
const int MAX_N = 100001;
const int INF = 1e9 + 1;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> path;
int dist[MAX_N];
int predist[MAX_N];
int start, target;

void init()
{
	cin >> start >> target;
	fill(dist, dist + MAX_N, INF);
}

void dijkstra()
{
	dist[start] = 0;
	pq.push({ dist[start], start });

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();

		if (dist[cur.second] != cur.first) continue;

		if (cur.second - 1 >= 0 && dist[cur.second - 1] > dist[cur.second] + 1)
		{
			dist[cur.second - 1] = dist[cur.second] + 1;
			pq.push({ dist[cur.second - 1], cur.second - 1 });
			predist[cur.second - 1] = cur.second;
		}
		if (cur.second + 1 < MAX_N && dist[cur.second + 1] > dist[cur.second] + 1)
		{
			dist[cur.second + 1] = dist[cur.second] + 1;
			pq.push({ dist[cur.second + 1], cur.second + 1 });
			predist[cur.second + 1] = cur.second;
		}
		if (cur.second * 2 < MAX_N && dist[cur.second * 2] > dist[cur.second] + 1)
		{
			dist[cur.second * 2] = dist[cur.second] + 1;
			pq.push({ dist[cur.second * 2], cur.second * 2 });
			predist[cur.second * 2] = cur.second;
		}
	}
	cout << dist[target] << "\n";
}

void find_dijkstra_path()
{
	if (start == target) { cout << target; return; }

	int curNode = target;
	while (curNode != start)
	{
		path.push_back(curNode);
		curNode = predist[curNode];;
	}
	path.push_back(start);
	reverse(path.begin(), path.end());

	for (int i = 0; i < path.size(); i++) cout << path[i] << " ";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	init();
	dijkstra();
	find_dijkstra_path();

	return 0;
}
