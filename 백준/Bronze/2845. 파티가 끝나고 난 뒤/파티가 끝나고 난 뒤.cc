#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int L, P; cin >> L >> P;
	int total = L * P;

	for (int i = 0; i < 5; i++)
	{
		int temp; cin >> temp;
		cout << temp - total << " ";
	}
	return 0;
}