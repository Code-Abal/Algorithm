#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
/*
3
A) 1 2 3
B) 3 2 1
AAB


6
A) 1 4 2 6 3 5
B) 2 3 1 6 5 4
ABBABA

*/

void A_Pick(vector<bool>& Pick, queue<int>& Aq, vector<char>& ans)
{
	while (!Aq.empty())
	{
		int Apick = Aq.front();
		Aq.pop();

		if (!Pick[Apick])
		{
			Pick[Apick] = true;
			ans[Apick] = 'A';
			return;
		}
	}
}

void B_Pick(vector<bool>& Pick, queue<int>& Bq, vector<char>& ans)
{
	while (!Bq.empty())
	{
		int Bpick = Bq.front();
		Bq.pop();

		if (!Pick[Bpick])
		{
			Pick[Bpick] = true;
			ans[Bpick] = 'B';
			return;
		}
	}
}

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int N; cin >> N;
		vector<bool> Pick(N + 1, false);
		queue<int> Aq, Bq;
		vector<char> ans(N + 1);
		for (int i = 0; i < N; i++)
		{
			int temp; cin >> temp;
			Aq.push(temp);
		}

		for (int i = 0; i < N; i++)
		{
			int temp; cin >> temp;
			Bq.push(temp);
		}

		while (!Aq.empty() && !Bq.empty())
		{
			A_Pick(Pick, Aq, ans);
			B_Pick(Pick, Bq, ans);
		}

		for (int i = 1; i <= N; i++)
		{
			cout << ans[i];
		}
		cout << "\n";
	}

	return 0;
}  