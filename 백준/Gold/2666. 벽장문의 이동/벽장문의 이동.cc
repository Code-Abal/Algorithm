#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> arr;
queue<int> q;
int N, openAIdx, openBIdx;
int minCnt = 2100000000;

void init()
{
	cin >> N;
	arr.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		arr[i] = i;
	}

	cin >> openAIdx >> openBIdx;

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int temp; cin >> temp;
		q.push(temp);
	}
}

void push(queue<int>& q, int curCnt, int openAIdx, int openBIdx)
{
	if (q.size() == 0) { minCnt = min(minCnt, curCnt); return; }
	if (curCnt >= minCnt) return;

	queue<int> copyQ = q;
	int target = copyQ.front();
	copyQ.pop();

	int cnt = abs(openAIdx - target);
	push(copyQ, curCnt + cnt, target, openBIdx);
	
	cnt = abs(openBIdx - target);
	push(copyQ, curCnt + cnt, openAIdx, target);
}

int main()
{
	init();
	push(q, 0, openAIdx, openBIdx);
	cout << minCnt;
	return 0;
}