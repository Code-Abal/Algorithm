#include <iostream>
#include <algorithm>
using namespace std;

int price[200001];
int N, profit = 0;

int main()
{
	cin >> N;
	int min_price = 1e9;
	int max_profit = 0;
	for (int i = 0; i < N; i++)
	{
		int stock; cin >> stock;
		max_profit = max(max_profit, stock - min_price);
		min_price = min(min_price, stock);
	}
	cout << max_profit;
	return 0;
}