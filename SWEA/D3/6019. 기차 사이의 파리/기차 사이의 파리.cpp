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
		float D, A, B, F;
		cin >> D >> A >> B >> F;

		float time = D / (A + B);
		float flytime = time * F;

		cout.precision(8);
		cout << "#" << tc << " " << flytime << "\n";
	}
	
	return 0;
}  
