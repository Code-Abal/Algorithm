#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long cycle(vector<vector<int>>& office, vector<vector<int>>& office_length, vector<vector<bool>>& visited, int start)
{
	vector<vector<bool>> visit = visited; //방문여부
	queue<pair<pair<int, int>,long long>> q; //{출발지와 목적지} 그리고 {누적거리}

	//N번째 건물과 연결된 도로 탐색
	for (const auto& next : office[start])
	{
		q.push({ { start, next }, 0 });
		visit[start][next] = true;
	}
	/*
	1
	3 3
	1 1 5
	1 2 3
	3 3 1

	*/
	//방문시작
	while (!q.empty())
	{
		int from = q.front().first.first;
		int current = q.front().first.second;
		long long length = q.front().second;
		q.pop();

		length += office_length[from][current];

		//다음 건물과 연결된 도로 탐색
		for (const auto& next : office[current])
		{
			//다음 목적지가 출발지와 같다면(싸이클이 존재) 종료하고, 
			//방문여부때문에 재방문은 불가능하므로, 다음 목적지와의 거리를 합해서 반환
			if (next == start)
			{
				return length + office_length[current][next];
			}
			if (!visit[current][next])
			{//다음 목적지 탐색 후 큐삽입과 방문여부 체크
				q.push({ {current, next}, length });
				visit[current][next] = true;
			}
		}
	}
	return 0;
}

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int N, M;
		cin >> N >> M;
		vector<vector<int>> office(N + 1); //건물
		vector<vector<int>> office_length(N + 1, vector<int>(N + 1, 10001)); //길이
		vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false)); //방문여부(무한루프 방지)
		int equal_ans = 10001;
		bool equal = false;
		for (int i = 0; i < M; i++)
		{
			int s, e, c;
			cin >> s >> e >> c;
			if (s == e)
			{
				equal_ans = min(c, equal_ans);
				equal = true;
			}
			office[s].push_back(e);
			office_length[s][e] = min(c, office_length[s][e]);
		}

		int ans = 2100000000; //최소값 비교 목적
		bool tf = false;
		for (int start = 1; start <= N; start++)
		{
			int length = cycle(office, office_length, visited, start);
			//싸이클이 존재 여부(cycle함수를 0으로 반환했기 때문에 length를 0으로 판별)
			if (length != 0)
			{
				ans = min(length, ans);
				tf = true;
			}
		}

		ans = min(ans, equal_ans);

		if (tf)
		{
			cout << "#" << tc << " " << ans << "\n";
		}
		else
		{
			cout << "#" << tc << " " << "-1" << "\n";
		}
	}
	return 0;
}  
