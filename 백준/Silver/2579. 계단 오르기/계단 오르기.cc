#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;

	cin >> N;
	
	vector<int> step(N + 1);
	vector<int> dp(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> step[i];
	}

	dp[0] = 0;
	dp[1] = step[1];
	dp[2] = dp[1] + step[2];


	for (int i = 3; i <= N; i++)
	{
		dp[i] = max(dp[i - 2] + step[i], dp[i - 3] + step[i - 1] + step[i]);
	}

	cout << dp[N];

	return 0;
}