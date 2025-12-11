using namespace std;
#include <iostream>
#include <vector>
#include <queue>

#define distance first
#define node second

const int MAX_N = 100001;
const int INF = 1e9;

priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
int dist[MAX_N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M; cin >> N >> M;
	fill(dist, dist + MAX_N, INF);

	dist[N] = 0;
	pq.push({ dist[N], N });

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();

		if (dist[cur.node] != cur.distance) continue;

		if (cur.node * 2 < MAX_N && dist[cur.node * 2] > dist[cur.node])
		{
			dist[cur.node * 2] = dist[cur.node];
			pq.push({ dist[cur.node], cur.node * 2 });
		}
		if (cur.node - 1 >= 0 && dist[cur.node - 1] > dist[cur.node] + 1)
		{
			dist[cur.node - 1] = dist[cur.node] + 1;
			pq.push({ dist[cur.node] + 1, cur.node - 1 });
		}
		if (cur.node + 1 < MAX_N && dist[cur.node + 1] > dist[cur.node] + 1)
		{
			dist[cur.node + 1] = dist[cur.node] + 1;
			pq.push({ dist[cur.node] + 1, cur.node + 1 });
		}
	}

	cout << dist[M];

	return 0;
}