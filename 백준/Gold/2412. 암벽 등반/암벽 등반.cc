#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, T, cnt = -1;
vector<int> xList[200001]; // T 최대값에 따라 충분히 크게 선언 (문제에 맞게 조정)

void bfs()
{
	queue<vector<int>> q;
	q.push({ 0, 0, 0 }); // {x, y, cnt}

	while (!q.empty()) {
		vector<int> info = q.front();
		int x = info[0];
		int y = info[1];
		int step = info[2];

		q.pop();

		if (y == T) {
			cnt = step;
			return;
		}

		for (int ny = y - 2; ny <= y + 2; ny++) {
			if (ny < 0 || ny > T) continue;

			for (int i = 0; i < (int)xList[ny].size(); i++) {
				int nx = xList[ny][i];
				if (abs(x - nx) <= 2) {
					q.push({ nx, ny, step + 1 });
					xList[ny].erase(xList[ny].begin() + i); // 방문처리
					i--;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

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
