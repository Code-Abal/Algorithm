#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr;
	for (int i = 0; i < 3; i++)
	{
		int a; cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < 3; i++) cout << arr[i] << " ";
	
	return 0;
}