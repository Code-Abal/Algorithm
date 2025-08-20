#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void search(vector<vector<int>>& arr, int N, int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i, j });
	arr[i][j] = 0;
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx >= 0 && ny >= 0 && nx < N && ny < N && arr[nx][ny] != 0)
			{
				arr[nx][ny] = 0;
				q.push({ nx, ny });
			}
		}
	}
}

void wine(vector<vector<int>>& arr, int N, int day)
{
	// day인 칸을 먹는다.
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (arr[i][j] == day)
			{
				arr[i][j] = 0;
			}
		}
	}
}

int cheez(vector<vector<int>>& arr, int N, int day)
{
	// day인 칸을 먹는다.
	wine(arr, N, day);

	// 덩어리 탐색을 위한 배열을 복사.
	// 복사배열을 기준으로, 값이 0이 아니면 탐색 및 카운트.
	// 기존 배열을 넘기면, day번째날에 값을 0으로 바꾸는 배열과 충돌발생.
	vector<vector<int>> copyArr = arr;
	int cheezCnt = 0;

	// 남은 덩어리 탐색
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			// 0이 아닌 값과 연결되어있는 모든 좌표를 탐색하기 때문에
			// 메소드 호출 후, 독립적인 덩어리만 남게 됨
			if (copyArr[i][j] != 0)
			{
				search(copyArr, N, i, j);
				cheezCnt++;
			}
		}
	}
	return cheezCnt;
}

int main()
{
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int N; cin >> N;
		vector<vector<int>> arr(N, vector<int>(N));
		vector<vector<bool>> visited(N, vector<bool>(N));
		int maxCheez = 0;
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				cin >> arr[i][j];
				maxCheez = max(maxCheez, arr[i][j]);
			}
		}
		int maxCheezMass = 1;
		int day = 1;
		for (size_t i = 0; i < maxCheez; i++)
		{
			maxCheezMass = max(maxCheezMass, cheez(arr, N, day));
			day++;
		}
		cout << "#" << tc << " " << maxCheezMass << "\n";
	}
	return 0;
}