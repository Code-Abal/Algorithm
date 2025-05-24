#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		cin >> N;

		vector<int> price(N);

		for (int i = 0; i < N; i++)
		{
			cin >> price[i];
		}

		int maxprice = price[price.size() - 1];
		long long profit = 0;
		for (int i = price.size() - 2; i >= 0; i--)
		{
			maxprice = max(price[i], maxprice);
			if (price[i] < maxprice)
			{
				profit += maxprice - price[i];
			}
		}
		cout << profit << "\n";
	}
	return 0;
}  