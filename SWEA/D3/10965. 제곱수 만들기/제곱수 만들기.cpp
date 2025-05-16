#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int main()
{
	int T;
	cin >> T;

	vector<int> ansarr;
	for (int tc = 1; tc <= T; tc++)
	{
		int A; cin >> A;
		map<int, int> arr;
		int ans = 1;
		for (int i = 2; i <= sqrt(A); i++)
		{
			while (A % i == 0)
			{
				arr[i]++;
				A /= i;
			}
		}

		if (A > 1)
		{
			arr[A]++;
		}

		for (auto a : arr)
		{
			if (a.second % 2 != 0)
			{
				ans *= a.first;
			}
		}
		ansarr.push_back(ans);
	}

	for (int i = 0; i < ansarr.size(); i++)
	{
		cout << "#" << i + 1 << " " << ansarr[i] << "\n";
	}
	
	return 0;
}  