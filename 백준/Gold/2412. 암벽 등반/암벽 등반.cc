#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, T, cnt = -1;
vector<int> xList[200001]; 

void bfs()
{
	queue<vector<int>> q;
	q.push({ 0, 0, 0 }); 

	while (!q.empty()) {
		vector<int> info = q.front();
		q.pop();

		if (info[1] == T) {
			cnt = info[2];
			return;
		}

		for (int ny = info[1] - 2; ny <= info[1] + 2; ny++) {
			if (ny < 0 || ny > T) continue;

			for (int i = 0; i < xList[ny].size(); i++) {
				int nx = xList[ny][i];
				if (abs(info[0] - nx) <= 2) {
					q.push({ nx, ny, info[2] + 1 });
					xList[ny].erase(xList[ny].begin() + i);
					i--;
				}
			}
		}
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cout.tie(nullptr);
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		xList[y].push_back(x);
	}

	bfs();
	cout << cnt << "\n";
	return 0;
}
