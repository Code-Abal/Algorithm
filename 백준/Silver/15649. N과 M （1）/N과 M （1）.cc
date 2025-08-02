#include <iostream>
#include <vector>
using namespace std;

void BackTrack(vector<int>& arr, vector<bool>& isused, int N, int M)
{
	if (arr.size() == M)
	{
		for (auto a : arr)
		{
			cout << a << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		vector<int> copyarr = arr;
		if (!isused[i])
		{
			copyarr.push_back(i);
			isused[i] = true;
			BackTrack(copyarr, isused, N, M);
			isused[i] = false;
		}
	}
	return;
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> arr;
	vector<bool> isused(N + 1, false);

	BackTrack(arr, isused, N, M);
	return 0;
}