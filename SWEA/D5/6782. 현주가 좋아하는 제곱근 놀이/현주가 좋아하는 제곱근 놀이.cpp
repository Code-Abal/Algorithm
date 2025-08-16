#include <iostream>
#include <math.h>
using namespace std;

bool isInt(double sqrtN)
{
	if (sqrtN == (long long)sqrtN) return true;
	return false;
}

int main()
{
	int T; 
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		long long N;
		cin >> N;

		int cnt = 0;
		if (N == 2)
		{
			cout << "#" << tc << " " << cnt << "\n";
			continue;
		}
		for (N; ; cnt++)
		{
			if (N == 2) break;
			else if (isInt(sqrt(N))) N = sqrt(N);
			else if (!isInt(sqrt(N)))
			{
				int prev = N;
				N = ((long long)(sqrt(N) + 1) * ((long long)sqrt(N) + 1));
				cnt += (N - prev) - 1;
			}
		}
		cout << "#" << tc << " " << cnt << "\n";
	}
	return 0;
}