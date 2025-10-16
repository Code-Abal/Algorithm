#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 20;
const int dx[4] = { 0, 0, 1, -1};
const int dy[4] = { 1, -1, 0, 0};
int N;
struct StudentInfo
{
	int studentNum;
	int loveLine[4];

	StudentInfo() : studentNum(-1), loveLine{}{}
	StudentInfo(int _studentNum, int _n1, int _n2, int _n3, int _n4) : studentNum(_studentNum), loveLine{ _n1, _n2, _n3, _n4 } {}
};

StudentInfo studentInfo[MAX_N * MAX_N + 1];
int seat[MAX_N + 1][MAX_N + 1];
int inputOrder[MAX_N * MAX_N + 1];

void init();
void setSeat();
void searchSeat(int studentNum);
void loveSurvey();
int loveStudentCnt(int studentNum, int i, int j);

void init()
{
	cin >> N;
	for (int i = 0; i < N * N; i++)
	{
		int studentNum, n1, n2, n3, n4;
		cin >> studentNum >> n1 >> n2 >> n3 >> n4;
		studentInfo[studentNum] = StudentInfo(studentNum, n1, n2, n3, n4);
		inputOrder[i + 1] = studentNum;
	}
}

// 시작(1,1) / 끝(N,N)
void setSeat()
{
	seat[2][2] = inputOrder[1]; // 첫 번째 학생 초기화
	for (int i = 2; i <= N * N; i++) searchSeat(inputOrder[i]);
}

void searchSeat(int studentNum)
{
	int loverow = 401, lovecol = 401;
	int maxLoveSeat = 0;
	int loveEmptycol = 401, loveEmptyrow = 401, maxLove_EmptySeat = 0;
	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (seat[i][j] != 0) continue; // 앉아있으면 패스 = 비어있는 자리라면

			int curEmptySeat = 0, curLoveSeat = 0;
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = i + dx[dir];
				int ny = j + dy[dir];

				if (nx >= 1 && ny >= 1 && nx <= N && ny <= N)
				{
					if (seat[nx][ny] == 0) curEmptySeat++;
					else
					{
						for (int line = 0; line < 4; line++)
							if (seat[nx][ny] == studentInfo[studentNum].loveLine[line]) curLoveSeat++;
					}
				}
			}
			// 아래에 4방에 대한 결과 처리.
			if (curLoveSeat > maxLoveSeat) // 더 큰 경우
			{
				maxLoveSeat = curLoveSeat;
				maxLove_EmptySeat = curEmptySeat; // 최대값일 때 빈 곳.
				loveEmptycol = i; loveEmptyrow = j;
			}
			else if (curLoveSeat == maxLoveSeat) // 같은 경우 작은 좌표
			{
				if (maxLove_EmptySeat < curEmptySeat) // 좋아하는 학생 수는 같은데 주변에 빈 곳이 더 많을 때 // 조건 2
				{
					maxLove_EmptySeat = curEmptySeat;
					loveEmptycol = i; loveEmptyrow = j;
				}
				else if (maxLove_EmptySeat == curEmptySeat) // 좋아하는 학생 수도 같고, 주변에 빈 곳도 같을 때 // 조건 3
				{
					if (loveEmptycol > i) // 행이 더 작은 경우
					{
						loveEmptycol = min(loveEmptycol, i);
						loveEmptyrow = j;
					}
					else if (loveEmptycol == i)
					{
						loveEmptyrow = min(loveEmptyrow, j);
					}
				}
			}
			lovecol = loveEmptycol;
			loverow = loveEmptyrow;
		}
	seat[lovecol][loverow] = studentNum; 
}

void loveSurvey()
{
	int score = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (loveStudentCnt(seat[i][j], i, j) == 1) score += 1;
			else if (loveStudentCnt(seat[i][j], i, j) == 2) score += 10;
			else if (loveStudentCnt(seat[i][j], i, j) == 3) score += 100;
			else if (loveStudentCnt(seat[i][j], i, j) == 4) score += 1000;
		}
	cout << score << "\n";
}

int loveStudentCnt(int studentNum, int i, int j)
{
	int studentLoveCnt = 0;
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = i + dx[dir];
		int ny = j + dy[dir];

		if (nx >= 1 && ny >= 1 && nx <= N && ny <= N)
		{
			for (int line = 0; line < 4; line++) 
				if (seat[nx][ny] == studentInfo[studentNum].loveLine[line]) studentLoveCnt++;
		}
	}
	return studentLoveCnt;
}

int main()
{
	init();
	setSeat();
	loveSurvey();
	return 0;
}