#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, stock;
	cin >> N;
	int min_price = 1e9;
	int max_profit = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> stock;
		max_profit = max(max_profit, stock - min_price);
		min_price = min(min_price, stock);
	}
	cout << max_profit;
	return 0;
}