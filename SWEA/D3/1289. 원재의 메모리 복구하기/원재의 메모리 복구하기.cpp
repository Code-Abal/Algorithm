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
		string memory;
		cin >> memory;

		char bit = '0';
		int cnt = 0;
		for (char c : memory)
		{
			if (c != bit)
			{
				bit = c;
				cnt++;
			}
		}
		cout << "#" << tc << " " << cnt << "\n";
	}
	return 0;
}  
