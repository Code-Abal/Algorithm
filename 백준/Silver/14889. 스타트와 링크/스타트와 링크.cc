#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

void BackTrack(vector<int>& arr, deque<vector<int>>& dq, int idx, int N, int M)
{
	if (arr.size() == M)
	{
		dq.push_back(arr);
		return;
	}

	for (int i = idx; i <= N; i++)
	{
		vector<int> copyarr = arr;
		copyarr.push_back(i);
		BackTrack(copyarr, dq, i + 1, N, M);
	}
	return;
}

int main()
{
	int N;
	cin >> N;
	
	vector<vector<int>> team(N + 1, vector<int>(N + 1));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> team[i][j];
		}
	}

	//조합 추출
	vector<int> arr;
	deque<vector<int>> dq;
	BackTrack(arr, dq, 1, N, N / 2);

	int minpower = 2100000000;
	while (!dq.empty())
	{
		vector<int> start = dq.front();
		vector<int> link = dq.back();
		dq.pop_front();
		dq.pop_back();

		int startpower = 0;
		int linkpower = 0;
		for (int i = 0; i < start.size() - 1; i++)
		{
			for (int j = i + 1; j < start.size(); j++)
			{
				startpower += team[start[i]][start[j]] + team[start[j]][start[i]];
				linkpower += team[link[i]][link[j]] + team[link[j]][link[i]];
			}
		}
		int power = abs(startpower - linkpower);
		minpower = min(minpower, power);
	}
	cout << minpower;
	return 0;
}