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

	for (int tc = 1; tc <= T; tc++)
	{
		long long A, B;
		cin >> A >> B;

		long long ans = 0;
		long long minus = B - A;
		if (minus == 1 || minus < 0)
		{
			ans = -1;
		}
		else if (minus == 0)
		{
			ans = 0;
		}
		else 
		{ 
			ans = minus / 2;
		}

		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}  