#include <iostream>
#include <map>
using namespace std;

int main()
{
	int T; cin >> T;
	
	for (int tc = 1; tc <= T; tc++)
	{
		multimap<long long, long long> mtMap;
		int K; cin >> K;

		for (int k = 0; k < K; k++)
		{
			char cmd; long long n;
			cin >> cmd >> n;

			if (cmd == 'I')mtMap.emplace(make_pair(n, n));
			else
			{
				if (mtMap.size() == 0) continue;
				if (n == 1) mtMap.erase(prev(mtMap.end()));
				else mtMap.erase(mtMap.begin());
			}
		}
		if (mtMap.size() == 0) cout << "EMPTY" << "\n";
		else cout << prev(mtMap.end())->second  << " " << mtMap.begin()->second  << "\n";
	}
	return 0;
}