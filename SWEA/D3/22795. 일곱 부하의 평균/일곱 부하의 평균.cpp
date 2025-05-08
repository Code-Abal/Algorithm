#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		vector<int> arr(6);
		int sum = 0;
		int high = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			cin >> arr[i];
			sum += arr[i];
			high = max(high, arr[i]);
		}

		int seven = high + 1;
		while (1)
		{
			if ((sum + seven) % 7 == 0)
			{
				break;
			}
			seven++;
		}
		cout << seven << "\n";
	}
	return 0;
}  