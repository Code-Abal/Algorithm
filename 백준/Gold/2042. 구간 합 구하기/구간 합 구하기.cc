#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 1000000
#define MAX_M 10000
#define MAX_K 10000

long long arr[MAX_N];
long long tree[MAX_N * 4];

void init(int node, int start, int end);
long long sectionSum(int node, int start, int end, int left, int right);
void update(int node, int start, int end, int index, long long val);

void init(int node, int start, int end)
{
	if (start == end) tree[node] = arr[start];
	else
	{
		init(node * 2, start, (start + end) / 2); // 왼쪽 노드
		init(node * 2 + 1, (start + end) / 2 + 1, end); // 오른쪽 노드
		tree[node] = tree[node * 2] + tree[node * 2 + 1]; // 자식 노드의 합, 저장. 
	}
}

long long sectionSum(int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0; // 범위 밖
	if (left <= start && end <= right) return tree[node]; // 범위 안
		
	long long lsum = sectionSum(node * 2, start, (start + end) / 2, left, right);       // 왼쪽 노드 탐색
	long long rsum = sectionSum(node * 2 + 1, (start + end) / 2 + 1, end, left, right); // 오른쪽 노드 탐색
	return lsum + rsum;
}

void update(int node, int start, int end, int index, long long val)
{
	if (index < start || index > end) return; // 범위 밖
		
	if (start == end)
	{
		arr[index] = val;
		tree[node] = val;
		return;
	}
	update(node * 2, start, (start + end) / 2, index, val);
	update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) cin >> arr[i];
		
	init(1, 0, N - 1);// 세그먼트 트리 초기화 init(루트노드, 시작 인덱스, 끝 인덱스)

	for (int i = 0; i < M + K; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 1)	update(1, 0, N - 1, b - 1, c); // 세그먼트 트리 업데이트 함수 update(시작 인덱스, 끝 인덱스, 변경할 인덱스, 변경할 값)
		else cout << sectionSum(1, 0, N - 1, b - 1, c - 1) << "\n"; // 세그먼트 트리 구간 합 함수 query(루트 노드, 시작 인덱스, 끝 인덱스, 구간 시작 인덱스, 구간 끝 인덱스)
	}
	return 0;
}