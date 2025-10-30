#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Climbing
{
	int x, y, cnt;
	Climbing(int _x, int _y, int _cnt) { x = _x; y = _y; cnt = _cnt; }
};

int N, T, cnt = -1;
vector<Climbing> xList[50001];

void bfs()
{
	queue<Climbing> q;
	q.push(Climbing(0,0,0));

	while (!q.empty()) {
		Climbing info = q.front();
		q.pop();

		if (info.y == T) {
			cnt = info.cnt;
			return;
		}

		for (int ny = info.y - 2; ny <= info.y + 2; ny++) {
			if (ny < 0 || ny > T) continue;

			for (int i = 0; i < xList[ny].size(); i++) {
				int nx = xList[ny][i].x;

				if (abs(info.x - nx) <= 2) {
					q.push(Climbing( nx, ny, info.cnt + 1 ));
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
		xList[y].push_back(Climbing(x, y, 0));
	}

	bfs();
	cout << cnt << "\n";
	return 0;
}
