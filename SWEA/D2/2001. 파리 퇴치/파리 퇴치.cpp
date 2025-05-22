#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int N, M;
		cin >> N >> M;

		vector<vector<int>> arr(N, vector<int>(N, 0));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}

		int fly = 0;

		for (int i = 0; i <= N - M; i++)
		{
			for (int j = 0; j <= N - M; j++)
			{
				int catchfly = 0;
				for (int fly_i = 0; fly_i < M; fly_i++)
				{
					for (int fly_j = 0; fly_j < M; fly_j++)
					{
						catchfly += arr[i + fly_i][j + fly_j];
					}
				}
				fly = max(fly, catchfly);
			}
		}
		cout << "#" << tc << " " << fly << "\n";
	}
	
	return 0;
}  
