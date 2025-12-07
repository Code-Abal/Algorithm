using namespace std;
#include<iostream>

int main()
{
	while (1)
	{
		int a, b; cin >> a >> b;
		if (a == 0 && b == 0) break;

		if (a < b) b % a == 0 ? cout << "factor\n" : cout << "neither\n";
		else if (a > b) a % b == 0 ? cout << "multiple\n" : cout << "neither\n";
	}
	return 0;
}