#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		string original, write;
		int N;
		cin >> N >> original >> write;
		
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			if (original[i] != write[i])
			{
				cnt++;
			}
		}
		cout << "#" << tc << " " << N - cnt << "\n";
	}
	return 0;
}  
