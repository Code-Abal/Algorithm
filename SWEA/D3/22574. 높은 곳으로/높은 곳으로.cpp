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
		int N, P;
		cin >> N >> P;

		int cur = 0;
		bool bomb = false;
		for (int i = 1; i <= N; i++)
		{
			cur += i;
			if (cur == P)
			{
				bomb = true;
			}
		}

		if (bomb)
		{
			cur -= 1;
		}
		
		cout << cur << "\n";
	}
	return 0;
}  