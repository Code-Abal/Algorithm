#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		string str; cin >> str;
		int rightidx = str.length() - 1;
		int leftidx = 0;
		int ans = 0;
		while (leftidx < rightidx)
		{
			char rightch = str.at(rightidx);
			char leftch = str.at(leftidx);

			if (rightch == leftch)
			{
				leftidx++;
				rightidx--;
			}
			else if (rightch == 'x')
			{
				rightidx--;
				ans++;
			}
			else if (leftch == 'x')
			{
				leftidx++;
				ans++;
			}
			else
			{
				ans = -1;
				break;
			}
		}

		cout << ans << "\n";

	}
	return 0;
}  
