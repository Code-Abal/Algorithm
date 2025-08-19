#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
문자	의미
.	평지(전차가 들어갈 수 있다.)
*	벽돌로 만들어진 벽
#	강철로 만들어진 벽
-	물(전차는 들어갈 수 없다.)
^	위쪽을 바라보는 전차(아래는 평지이다.)
v	아래쪽을 바라보는 전차(아래는 평지이다.)
<	왼쪽을 바라보는 전차(아래는 평지이다.)
>	오른쪽을 바라보는 전차(아래는 평지이다.)

다음 표는 사용자가 넣을 수 있는 입력의 종류를 나타낸다.

문자	동작
U	Up : 전차가 바라보는 방향을 위쪽으로 바꾸고, 한 칸 위의 칸이 평지라면 위 그 칸으로 이동한다.
D	Down : 전차가 바라보는 방향을 아래쪽으로 바꾸고, 한 칸 아래의 칸이 평지라면 그 칸으로 이동한다.
L	Left : 전차가 바라보는 방향을 왼쪽으로 바꾸고, 한 칸 왼쪽의 칸이 평지라면 그 칸으로 이동한다.
R	Right : 전차가 바라보는 방향을 오른쪽으로 바꾸고, 한 칸 오른쪽의 칸이 평지라면 그 칸으로 이동한다.
S	Shoot : 전차가 현재 바라보고 있는 방향으로 포탄을 발사한다.
*/

// shoot 메소드
// 우, 하, 좌, 상
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };



void shoot(vector<vector<char>>& arr, int H, int W, int tankX, int tankY, int dir)
{
	int nx = tankX;
	int ny = tankY;

	while (1)
	{
		nx += dx[dir];
		ny += dy[dir];

		if (nx < 0 || ny < 0 || nx >= H || ny >= W || arr[nx][ny] == '#') return;

		if (arr[nx][ny] == '*')
		{
			arr[nx][ny] = '.';
			return;
		}
	}
}

void tank(vector<vector<char>>& arr, queue<char>& command, int H, int W, int& tankX, int& tankY, int& dir)
{
	while (!command.empty())
	{
		char cmd = command.front();
		command.pop();

		bool go = false;
		if (cmd == 'U')
		{
			dir = 3; 
			go = true;
		}
		if (cmd == 'D')
		{
			dir = 1;
			go = true;
		}
		if (cmd == 'L')
		{
			dir = 2;
			go = true;
		}
		if (cmd == 'R')
		{
			dir = 0;
			go = true;
		}
		if (cmd == 'S') shoot(arr, H, W, tankX, tankY, dir);

		int nx = tankX + dx[dir];
		int ny = tankY + dy[dir];

		if (nx >= 0 && ny >= 0 && nx < H && ny < W && go && arr[nx][ny] =='.')
		{
			tankX = nx;
			tankY = ny;
		}
	}
}

int main() {
	
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int H, W;
		cin >> H >> W;
		int tankX, tankY, dir;
		vector<vector<char>> arr(H, vector<char>(W));
		queue<char> command;

		for (size_t i = 0; i < H; i++)
		{
			for (size_t j = 0; j < W; j++)
			{
				cin >> arr[i][j];
				char c = arr[i][j];
				if (c == 'v')
				{
					tankX = i;
					tankY = j;
					dir = 1;
					arr[i][j] = '.';
				}
				if (c == '<')
				{
					tankX = i;
					tankY = j;
					dir = 2;
					arr[i][j] = '.';
				}
				if (c == '>')
				{
					tankX = i;
					tankY = j;
					dir = 0;
					arr[i][j] = '.';
				}
				if (c == '^')
				{
					tankX = i;
					tankY = j;
					dir = 3;
					arr[i][j] = '.';
				}
			}
		}

		int N; cin >> N;
		for (int i = 0; i < N; i++)
		{
			char c; cin >> c;
			command.push(c);
		}

		tank(arr, command, H, W, tankX, tankY, dir);

		if (dir == 0) arr[tankX][tankY] = '>';
		else if (dir == 1) arr[tankX][tankY] = 'v';
		else if (dir == 2) arr[tankX][tankY] = '<';
		else if (dir == 3) arr[tankX][tankY] = '^';

		cout << "#" << tc << " ";
		for (size_t i = 0; i < H; i++)
		{
			for (size_t j = 0; j < W; j++)
			{
				cout << arr[i][j];
			}
			cout << "\n";
		}
	}

	return 0;
}

