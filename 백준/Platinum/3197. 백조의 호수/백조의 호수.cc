#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// 방향 
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

bool search(vector<vector<char>>& arr, queue<pair<int, int>>& searchQ, queue<pair<int, int>>& next_searchQ, 
			pair<int,int> swanpos, vector<vector<bool>>& swanvisited, vector<vector<bool>>& watervisited, int R, int C)
{
	while (!searchQ.empty())
	{
		int x = searchQ.front().first;
		int y = searchQ.front().second;
		searchQ.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx >= 0 && ny >= 0 && nx < R && ny < C && !swanvisited[nx][ny])
			{
				// '점' 부분은 전부 탐색(생략)
				if (arr[nx][ny] == '.')
				{
					searchQ.push({ nx,ny });
					swanvisited[nx][ny] = true;
				}
				// 'X' 부분은 물을 녹인 이후 다음 회차에 진행
				else if (arr[nx][ny] == 'X')
				{
					next_searchQ.push({ nx, ny });
					swanvisited[nx][ny] = true;
				}
				// 'L'값으로 찾느냐 or 좌표값(swanend)로 찾느냐 시도해봐야함.
				// 좌표값으로 찾아야함. 'L'값으로도 중단시킬 수 있을 것 같은데 왜 안됨
				else if (nx == swanpos.first && ny == swanpos.second)
				{
					return true;
				}
			}
		}
	}
	return false;
}

void water(vector<vector<char>>& arr, queue<pair<int, int>>& waterQ, queue<pair<int, int>>& next_waterQ, vector<vector<bool>>& watervisited, int R, int C)
{
	while (!waterQ.empty())
	{
		int x = waterQ.front().first;
		int y = waterQ.front().second;

		waterQ.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx >= 0 && ny >= 0 && nx < R && ny < C && !watervisited[nx][ny])
			{
				// 'X'인 부분은 녹임('점')
				if (arr[nx][ny] == 'X')
				{
					arr[nx][ny] = '.';
					// 다음 날 녹일 범위 저장
					next_waterQ.push({ nx, ny }); 
					watervisited[nx][ny] = true;
				}
				else if(arr[nx][ny] == '.')
				{
					waterQ.push({ nx, ny });
					watervisited[nx][ny] = true;
				}
			}
		}
	}
}

int main()
{
	int T;
	//cin >> T;
	for (int tc = 1; tc <= 1; tc++)
	{
		int R, C; cin >> R >> C;

		vector<vector<char>> arr(R, vector<char>(C));
		vector<vector<int>> waterDay(R, vector<int>(C, 0));
		vector<vector<bool>> swanvisited(R, vector<bool>(C, false));
		vector<vector<bool>> watervisited(R, vector<bool>(C, false));
		queue<pair<int, int>> searchQ, next_searchQ;
		queue<pair<int, int>> waterQ, next_waterQ;
		pair<int, int> swanstart, swanend;
		bool find = false;

		for (int i = 0; i < R; i++)
		{
			string temp; cin >> temp;
			for (int j = 0; j < C; j++)
			{
				arr[i][j] = temp[j];
				if (arr[i][j] == 'L')
				{
					if (!find)
					{
						swanstart.first = i;
						swanstart.second = j;
						find = true;
						waterQ.push({ i, j });
					}
					else
					{
						swanend.first = i;
						swanend.second = j;
						waterQ.push({ i, j });
					}
				}
				else if (arr[i][j] == '.')
				{
					waterQ.push({ i, j });
					watervisited[i][j] = true;
				}
			}
		}

		// 백조 시작점
		searchQ.push({ swanstart.first, swanstart.second });
		swanvisited[swanstart.first][swanstart.second] = true;

		int day = 0;
		
		while (1)
		{
			// 백조 찾기 & 다음 이동 범위 저장
			bool tf = search(arr, searchQ, next_searchQ, swanend, swanvisited, watervisited, R, C);
			if (tf) break;

			// 물 녹이기 & 다음 녹일 범위 저장
			water(arr, waterQ, next_waterQ, watervisited, R, C);

			waterQ = next_waterQ;
			searchQ = next_searchQ;

			// 다음 백조이동 & 물 녹일 범위 큐 사용했으니, 초기화
			while (!next_waterQ.empty()) next_waterQ.pop();
			while (!next_searchQ.empty()) next_searchQ.pop();

			day++;
		}
		cout << day << "\n";

	}
	return 0;
}