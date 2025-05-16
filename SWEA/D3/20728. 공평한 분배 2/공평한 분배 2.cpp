#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int N, K;
		cin >> N >> K;

		vector<int> pocket(N);

		for (int i = 0; i < N; i++)
		{
			cin >> pocket[i];
		}

		sort(pocket.begin(), pocket.end(), [](int& A, int& B)
		{
			return A < B;
		});

		int min_candy = 1000000001;
		for (int i = 0; i <= N - K; i++)
		{
			min_candy = min(min_candy, pocket[i + K - 1] - pocket[i]);
		}

		cout << "#" << tc << " " << min_candy << "\n";

	}
	return 0;
}  