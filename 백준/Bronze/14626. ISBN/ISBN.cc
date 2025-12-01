#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	int unknown = 0;
	for (int i = 0; i < 13; i++)
	{
		char isbn; cin >> isbn;
		if (isbn != '*')
		{
			int w = i % 2 == 0 ? 1 : 3;
			sum += (isbn - '0') * w;
		}
		else unknown = i % 2 == 0 ? 1 : 3;
	}
	
	for (int i = 0; i <= 9; i++) { if ((sum + unknown * i) % 10 == 0) { cout << i; break; } }

	return 0;
}