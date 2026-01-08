#include <iostream>
using namespace std;

#define x first
#define y second

const int MAX_N = 101;
int arr[MAX_N][MAX_N];
long long dp[MAX_N][MAX_N];
int N;
long long ans = 0;

void init()
{
	cin >> N;

	fill(&arr[0][0], &arr[MAX_N - 1][MAX_N], -1);
	fill(&dp[0][0], &dp[MAX_N - 1][MAX_N], 0);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
}

void search()
{
	dp[0][0] = 1;

	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (dp[i][j] == 0) continue;
			if (arr[i][j] == 0) continue;

			int jump = arr[i][j];

			if (i + jump < N) dp[i + jump][j] += dp[i][j];
			if (j + jump < N) dp[i][j + jump] += dp[i][j];
		}
}
int main()
{
	init();
	search();
	cout << dp[N - 1][N - 1];
	return 0;
}