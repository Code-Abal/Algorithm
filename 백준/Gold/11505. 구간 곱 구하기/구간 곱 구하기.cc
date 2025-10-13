#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_INT INT32_MAX

const int MAX_N = 1000000;
const int MAX_M = 100000;
const long long comPress = 1000000007;

struct Node
{
	long long multiNode;
	Node() : multiNode(1) {}
	Node(long long _multiNode) : multiNode(_multiNode) {}
};

// property
Node segTree[MAX_N * 4];
long long arr[MAX_N];

void init(int node, int start, int end);
void update(int node, int start, int end, int index, int value);
long long sectionMulti(int node, int start, int end, int left, int right);

void init(int node, int start, int end)
{
	if (start == end) segTree[node] = Node(arr[start]);
	else
	{
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		segTree[node] = Node(((segTree[node * 2].multiNode % comPress) * (segTree[node * 2 + 1].multiNode % comPress)) % comPress);
	}
}

void update(int node, int start, int end, int index, int value)
{
	if (start > index || end < index) return;
	if (start == end)
	{
		arr[index] = value;
		segTree[node] = Node(arr[index]);
		return;
	}
	update(node * 2, start, (start + end) / 2, index, value);
	update(node * 2 + 1, (start + end) / 2 + 1, end, index, value);
	segTree[node] = Node((segTree[node * 2].multiNode % comPress) * (segTree[node * 2 + 1].multiNode % comPress) % comPress);
}

long long sectionMulti(int node, int start, int end, int left, int right)
{
	// 구간 설정할 때, 신중하게 생각할 것.
	// start와 end는 고정값이고, 총 범위를 줄여나갈 것.
	if (left > end || right < start) return Node().multiNode;
	if (start <= left && right <= end) return segTree[node].multiNode;

	long long LNode = sectionMulti(node * 2, start, end, left, (left + right) / 2);
	long long RNode = sectionMulti(node * 2 + 1, start, end, ((left + right) / 2) + 1, right);

	return ((LNode % comPress) * (RNode % comPress)) % comPress;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K; 
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) cin >> arr[i];

	init(1, 0, N - 1);

	for (int i = 0; i < M + K; i++)
	{
		int cmd; cin >> cmd; // 1이면, update
		if (cmd == 1)
		{
			int idx, value;
			cin >> idx >> value;
			update(1, 0, N - 1, idx - 1, value);
		}
		else
		{
			int start, end;
			cin >> start >> end;
			cout << sectionMulti(1, start - 1, end - 1, 0, N - 1) << "\n";
		}
	}
	return 0;
}