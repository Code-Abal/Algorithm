#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		string S, E;
		cin >> S >> E;

		bool ans = false;
		while (E.size() > S.size())
		{
			
			if (E.back() == 'X')
			{
				E.erase(E.end() - 1);
			}
			else if (E.back() == 'Y')
			{
				E.erase(E.end() - 1);
				reverse(E.begin(), E.end());
			}
			
			if (E == S)
			{
				ans = true;
				break;
			}
		}

		if (ans)
		{
			cout << "#" << tc << " " << "Yes" << "\n";
		}
		else
		{
			cout << "#" << tc << " " << "No" << "\n";
		}
	}
	return 0;
}  