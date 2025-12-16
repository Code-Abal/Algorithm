#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() 
{
	int N; cin >> N;
	vector<string> names(N);
	for (int i = 0; i < N; ++i) cin >> names[i];

	string pattern = names[0];
	for (int i = 1; i < N; ++i) 
	{
		for (int j = 0; j < pattern.size(); ++j) if (pattern[j] != names[i][j]) pattern[j] = '?';
	}

	cout << pattern << '\n';
	return 0;
}