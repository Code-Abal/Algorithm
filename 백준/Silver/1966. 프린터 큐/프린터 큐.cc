#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		queue<pair<int,bool>> q;
		priority_queue<int> pq;
		int N, find;
		cin >> N >> find;

		for (int i = 0; i < N; i++)
		{
			int a; cin >> a;
			pq.push(a);
			if (i == find)
			{
				q.push({ a, true });
			}
			else q.push({ a, false });
		}
		int outcnt = 0;
		while (!q.empty())
		{
			int doc = q.front().first;
			bool findtf = q.front().second;
			q.pop();

			int prior = pq.top();

			if (doc == prior)
			{
				pq.pop();
				outcnt++;
				if (findtf)
				{
					break;
				}
			}
			else
			{
				q.push({ doc, findtf });
			}
		}
		cout << outcnt << "\n";
	}
	return 0;
}  