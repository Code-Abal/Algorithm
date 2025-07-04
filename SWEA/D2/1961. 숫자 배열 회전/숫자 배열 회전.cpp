#include<iostream>
#include<vector>

using namespace std;

void square(vector<vector<int>>& arr, vector<int>& snail_seq, int N)
{
	vector<vector<bool>> visited(N, vector<bool>(N, false));

	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };

	int x = 0;
	int y = 0;
	int dir = 0;

	for (int i = 0; i < N * N; i++)
	{
		snail_seq.push_back(arr[x][y]);
		visited[x][y] = true;

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny] == true)
		{
			dir = (dir + 1) % 4;
			nx = x + dx[dir];
			ny = y + dy[dir];
		}
		x = nx;
		y = ny;
	}
}

vector<vector<int>> temp(vector<int>& snail_seq, int N, int start_x, int start_y, int ndir)
{
	vector<vector<int>> turn(N, vector<int>(N));
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };

	int dir = ndir;
	
	int x = start_x;
	int y = start_y;

	for (int snail_val : snail_seq)
	{
		turn[x][y] = snail_val;
		visited[x][y] = true;

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny] == true)
		{
			dir = (dir + 1) % 4;
			nx = x + dx[dir];
			ny = y + dy[dir];
		}
		x = nx;
		y = ny;
	}
	return turn;
}

int main()
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;

		vector<vector<int>> arr(N, vector<int>(N));
		vector<vector<int>> ans90;
		vector<vector<int>> ans180;
		vector<vector<int>> ans270;
		vector<int> snail_seq;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}

		square(arr, snail_seq, N);

		ans90 = temp(snail_seq, N, 0, N - 1, 1);
		ans180 = temp(snail_seq, N, N - 1, N - 1, 2);
		ans270 = temp(snail_seq, N, N - 1, 0, 3);

		cout << "#" << test_case << " " << "\n";
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << ans90[i][j];
			}
			cout << " ";
			for (int j = 0; j < N; j++)
			{
				cout << ans180[i][j];
			}
			cout << " ";
			for (int j = 0; j < N; j++)
			{
				cout << ans270[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}