#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() 
{
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int A, B;
		char ch;
		cin >> A >> ch >> B;
		cout << A + B << "\n"; 
	}
	return 0;
}