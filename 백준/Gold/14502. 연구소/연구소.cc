#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 이동 방향 (상, 하, 좌, 우)
const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

// 바이러스 확산 BFS 함수
void spreadVirus(vector<vector<int>>& tempLab, int n, int m) {
    queue<pair<int, int>> q;

    // 바이러스 초기 위치를 큐에 삽입
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tempLab[i][j] == 2) {
                q.push({ i, j });
            }
        }
    }

    // BFS 실행
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && tempLab[nx][ny] == 0) {
                tempLab[nx][ny] = 2;
                q.push({ nx, ny });
            }
        }
    }
}

// 안전 영역 계산 함수
int getSafeArea(const vector<vector<int>>& tempLab, int n, int m) {
    int safeArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tempLab[i][j] == 0) {
                safeArea++;
            }
        }
    }
    return safeArea;
}

// 벽 세우기와 최대 안전 영역 계산 함수
void buildWall(vector<vector<int>>& lab, int n, int m, int count, int& maxSafeArea) {
    if (count == 3) {
        // 임시 맵에 복사
        vector<vector<int>> tempLab = lab;

        // 바이러스 확산 시뮬레이션
        spreadVirus(tempLab, n, m);

        // 안전 영역 계산
        maxSafeArea = max(maxSafeArea, getSafeArea(tempLab, n, m));
        return;
    }

    // 모든 빈 칸에 벽을 세우는 경우의 수 탐색
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lab[i][j] == 0) { // 빈 칸에 벽 세우기
                lab[i][j] = 1;
                buildWall(lab, n, m, count + 1, maxSafeArea);
                lab[i][j] = 0; // 벽 다시 제거
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> lab(n, vector<int>(m));

    // 연구소 맵 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
        }
    }

    int maxSafeArea = 0;

    // 벽 세우기 시작
    buildWall(lab, n, m, 0, maxSafeArea);

    // 최대 안전 영역 출력
    cout << maxSafeArea << endl;

    return 0;
}
