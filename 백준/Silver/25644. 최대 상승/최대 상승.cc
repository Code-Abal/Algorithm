#include <iostream>
#include <algorithm>
using namespace std;

int price[200001];
int N, profit = 0;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> price[i];

	int cur_price = price[N - 1];
	int min_price = price[N - 1];
	int max_profit = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		if (cur_price > price[i])
		{
			min_price = min(min_price, price[i]);
			if(i == 0)
			{
				profit = cur_price - min_price;
				max_profit = max(max_profit, profit);
				cur_price = price[i];
				min_price = price[i];
			}
		}
		else
		{
			profit = cur_price - min_price;
			max_profit = max(max_profit, profit);
			cur_price = price[i];
			min_price = price[i];
		}
	}
	cout << max_profit;
	return 0;
}