#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int graph[11][11];

struct Person
{
	int x, y;
};

struct Step
{
	int x, y, len;
};

int ans = 0;

void dfs(int cnt, vector<Person>& persons, vector<Step>& steps, vector<bool>& visited);
void calTime(vector<Person>& persons, vector<Step>& steps, vector<bool>& visited);
int solutionForStep(vector<int>& arrivalTimes, int stepLen);
void dfs(int cnt, vector<Person>& persons, vector<Step>& steps, vector<bool>& visited)
{
	if (cnt == persons.size())
	{
		calTime(persons, steps, visited);
		return;
	}

	visited[cnt] = true; // 1번 계단 선택
	dfs(cnt + 1, persons, steps, visited);
	visited[cnt] = false; // 0번 계단 선택
	dfs(cnt + 1, persons, steps, visited);
}

void calTime(vector<Person>& persons, vector<Step>& steps, vector<bool>& visited)
{
	vector<int> step0, step1;

	for (int i = 0; i < persons.size(); i++)
	{
		// 1번 계단 선택
		// 3명씩 묶어서 처리하게 되면, 6명인 경우에 반례
		if (visited[i])
		{
			int dist_Time = abs(persons[i].x - steps[1].x) + abs(persons[i].y - steps[1].y);
			step1.push_back(dist_Time);
		}
		else // 0번 계단 선택
		{
			int dist_Time = abs(persons[i].x - steps[0].x) + abs(persons[i].y - steps[0].y);
			step0.push_back(dist_Time);
		}
	}
	int step0Time = solutionForStep(step0, steps[0].len);
	int step1Time = solutionForStep(step1, steps[1].len);
	ans = min(ans, max(step0Time, step1Time));
}

int solutionForStep(vector<int>& arrivalTimes, int stepLen) 
{
	if (arrivalTimes.empty()) return 0;

	// 도착 시간 순으로 정렬 (Java의 PriorityQueue와 동일 효과)
	sort(arrivalTimes.begin(), arrivalTimes.end());

	priority_queue<int, vector<int> ,greater<int>> onStep;
	for (int arrivalTime : arrivalTimes) 
	{
		// 계단에 도착한 후 1분 뒤부터 내려갈 수 있음
		int readyTime = arrivalTime + 1;

		if (onStep.size() < 3)
		{
			// 계단에 자리가 있으면, 바로 내려가기 시작
			onStep.push(readyTime + stepLen);
		}
		else 
		{
			// 계단이 꽉 찼으면, 가장 먼저 내려가는 사람이 나올 때까지 기다림
			int firstDoneTime = onStep.top();
			onStep.pop();

			// 내가 준비된 시간과, 자리가 나는 시간 중 더 늦은 시간에 내려가기 시작
			int startTime = max(readyTime, firstDoneTime);
			onStep.push(startTime + stepLen);
		}
	}

	int maxTime = 0;
	while (!onStep.empty())
	{
		maxTime = onStep.top();
		onStep.pop();
	}
	return maxTime;
}

int main()
{
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int N; cin >> N;
		vector<Person> persons;
		vector<Step> steps;
		ans = INT32_MAX;

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				cin >> graph[i][j];
				if (graph[i][j] == 0) continue;
				if (graph[i][j] == 1)
				{
					persons.push_back({ i, j});
				}
				else steps.push_back({ i, j, graph[i][j]});
			}
		vector<bool> visited(persons.size());
		dfs(0, persons, steps, visited);

		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}