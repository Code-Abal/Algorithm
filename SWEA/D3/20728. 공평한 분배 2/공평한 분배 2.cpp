#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int compare(const int& a, const int& b)
{
	return a < b;
}

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		//첫 번째 예제: 주머니 2개를 고르는 방법은 {1, 2}, {1, 3}, {2, 3}이 있다. 
		//각각의 (최대) – (최소) 값은 1, 2, 1이다. 이 중 최솟값은 1이다.
		int N, K;
		cin >> N >> K;

		vector<int> pocket(N);

		for (int i = 0; i < N; i++)
		{
			cin >> pocket[i];
		}

		sort(pocket.begin(), pocket.end(), compare);

		int mincandy = INT_MAX;
		for (int i = 0; i <= N - K ; i++)

		{
			mincandy = min(mincandy, pocket[i + K - 1] - pocket[i]);
		}

		cout << "#" << tc << " " << mincandy << "\n";
	}
	return 0;
}  