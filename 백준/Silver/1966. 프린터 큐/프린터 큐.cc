#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
using namespace std;

vector<bool> ans(1000001, true);

int main() 
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);


	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		queue<pair<int, int>> q;
		priority_queue<int> maxq; 

		int N, M;
		cin >> N >> M;

		for (int i = 0; i < N; i++)
		{
			int temp;
			cin >> temp;
			q.push({ temp, i });
			maxq.push(temp);
		}

		bool run = true;
		int cnt = 0;

		while (run)
		{
			int max = maxq.top();
			int size = q.size();
			bool tfpop = false;
			for (int i = 0; i < size; i++)
			{
				if (q.front().first != max)
				{
					q.push(q.front());
					q.pop();
				}
				else if (q.front().second == M && q.front().first == max)
				{
					run = false;
					cnt++;
					cout << cnt << "\n";
					break;
				}
				else if (q.front().first == max)
				{
					tfpop = true;
					cnt++;
					break;
				}
			}

			if (tfpop)
			{
				q.pop();
				maxq.pop();
			}
		}
	}
	return 0;
}