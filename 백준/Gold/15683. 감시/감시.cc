#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_N 8
#define MAX_M 8

using namespace std;

struct CCTV
{
	int cctvNum, r, c;
	CCTV() : cctvNum(0), r(-1), c(-1) {}
	CCTV(int _cctvNum, int _r, int _c) : cctvNum(_cctvNum), r(_r), c(_c) {}
};

const int CCTV1[4][2] = { { 0, 1 }, {-1, 0}, {0, -1}, {1, 0} };
const int CCTV2[2][2][2] = { {{ 0, 1 }, {0, -1}}, {{ 1, 0 }, {-1, 0}} };
const int CCTV3[4][2][2] = { {{ 0, 1 }, {-1, 0}}, {{ 0, 1 }, {1, 0}}, {{ 1, 0 }, {0, -1}}, {{ 0, -1 }, {-1, 0}} };
const int CCTV4[4][3][2] = {{{0,1}, {-1,0}, {0,-1}},{{-1,0}, {0,-1}, {1,0}},{{0,-1}, {1,0}, {0,1}},{{1,0}, {0,1}, {-1,0}}};
const int CCTV5[4][2] = { { 0, 1 }, {-1, 0}, {0, -1}, {1, 0} };

vector<CCTV> cctv;
int N, M, maxLen, minArea = 210000000;

void init(int office[MAX_N + 1][MAX_M + 1]);
int TOD(int office[MAX_N + 1][MAX_M + 1]);
void setSearch(int idx, int office[MAX_N + 1][MAX_M + 1]);

void init(int office[MAX_N + 1][MAX_M + 1])
{
	cin >> N >> M;
	maxLen = max(N, M);
	for (int n = 0; n < N; n++)
		for (int m = 0; m < M; m++)
		{
			cin >> office[n][m];
			if (office[n][m] != 0 && office[n][m] != 6) cctv.push_back(CCTV(office[n][m], n, m));
		}
}

int TOD(int office[MAX_N + 1][MAX_M + 1])
{
	int ans = 0;
	for (int n = 0; n < N; n++)
		for (int m = 0; m < M; m++)
			if (office[n][m] == 0) ans++;
	return ans;
}

void setSearch(int idx, int office[MAX_N + 1][MAX_M + 1])
{
	if (idx == cctv.size()) {
		minArea = min(minArea, TOD(office));
		return;
	}

	CCTV curCCTV = cctv[idx];
	int r = curCCTV.r;
	int c = curCCTV.c;
	int cctvNum = curCCTV.cctvNum;

	if (cctvNum == 5)
	{
		for (auto& dir : CCTV5)
		{
			for (int d = 1; ; d++)
			{
				int nr = r + dir[0] * d;
				int nc = c + dir[1] * d;
				if (nr < 0 || nc < 0 || nr >= N || nc >= M || office[nr][nc] == 6) break;
				if (office[nr][nc] == 0)	office[nr][nc] = -1;
			}
		}
		setSearch(idx+1, office);
	}
	if (cctvNum == 4)
	{
		for (auto& set : CCTV4)
		{
			queue<pair<int, int>> posQ;
			for (auto& dir : set)
			{
				for (int d = 1; ; d++)
				{
					int nr = r + dir[0] * d;
					int nc = c + dir[1] * d;
					if (nr < 0 || nc < 0 || nr >= N || nc >= M || office[nr][nc] == 6) break;
					if (office[nr][nc] == 0)
					{
						office[nr][nc] = -1;
						posQ.push({ nr, nc });
					}
				}
			}
			setSearch(idx + 1, office);
			while (!posQ.empty()) // revoke
			{
				int r = posQ.front().first;
				int c = posQ.front().second;
				posQ.pop();
				office[r][c] = 0;
			}
		}
	}
	if (cctvNum == 3)
	{
		for (auto& set : CCTV3)
		{
			queue<pair<int, int>> posQ;
			for (auto& dir : set)
			{
				for (int d = 1; ; d++)
				{
					int nr = r + dir[0] * d;
					int nc = c + dir[1] * d;
					if (nr < 0 || nc < 0 || nr >= N || nc >= M || office[nr][nc] == 6) break;
					if (office[nr][nc] == 0)
					{
						office[nr][nc] = -1;
						posQ.push({ nr, nc });
					}
				}
			}
			setSearch(idx + 1, office);
			while (!posQ.empty()) // revoke
			{
				int r = posQ.front().first;
				int c = posQ.front().second;
				posQ.pop();
				office[r][c] = 0;
			}
		}
	}
	if (cctvNum == 2)
	{
		//const int CCTV2[2][2][2] = { {{ 0, 1 }, {0, -1}}, {{ 1, 0 }, {-1, 0}} };
		for (auto& set : CCTV2)
		{
			queue<pair<int, int>> posQ;
			for (auto& dir : set)
			{
				for (int d = 1; ; d++)
				{
					int nr = r + dir[0] * d;
					int nc = c + dir[1] * d;
					if (nr < 0 || nc < 0 || nr >= N || nc >= M || office[nr][nc] == 6) break;
					if (office[nr][nc] == 0)
					{
						office[nr][nc] = -1;
						posQ.push({ nr, nc });
					}
				}
			}
			setSearch(idx + 1, office);

			while (!posQ.empty()) // revoke
			{
				int r = posQ.front().first;
				int c = posQ.front().second;
				posQ.pop();
				office[r][c] = 0;
			}
		}
	}
	if (cctvNum == 1)
	{
		queue<pair<int, int>> posQ;
		for (auto& dir : CCTV1)
		{
			for (int d = 1; ; d++)
			{
				int nr = r + dir[0] * d;
				int nc = c + dir[1] * d;
				if (nr < 0 || nc < 0 || nr >= N || nc >= M || office[nr][nc] == 6) break;
				if (office[nr][nc] == 0)
				{
					office[nr][nc] = -1;
					posQ.push({ nr, nc });
				}
			}
			setSearch(idx + 1, office);

			while (!posQ.empty()) // revoke
			{
				int r = posQ.front().first;
				int c = posQ.front().second;
				posQ.pop();
				office[r][c] = 0;
			}
		}
	}
}

int main()
{
	int office[MAX_N + 1][MAX_M + 1];
	init(office);
	setSearch(0, office);
	cout << minArea;
	return 0;
}