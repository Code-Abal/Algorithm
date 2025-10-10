#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_INT INT32_MAX
const int MAX_N = 100000;
const int MAX_M = 100000;

struct Node
{
	int minNode;
	Node() : minNode(MAX_INT) {}
	Node(int _minNode) : minNode(_minNode) {}
};

// property
Node segTree[MAX_N * 4];
int arr[MAX_N];

void init(int node, int start, int end);
void update(int node, int start, int end, int index, int value);
Node findMinNode(int node, int start, int end, int left, int right);

void init(int node, int start, int end)
{
	if (start == end) segTree[node] = Node(arr[start]);
	else
	{
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		segTree[node] = Node(min(segTree[node * 2].minNode, segTree[node * 2 + 1].minNode));
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
	segTree[node] = Node(min(segTree[node * 2].minNode, segTree[node * 2 + 1].minNode));
}

Node findMinNode(int node, int start, int end, int left, int right)
{
	if (start > right || end < left) return Node();
	if (left <= start && end <= right) return segTree[node];
	Node LNode = findMinNode(node * 2, start, (start + end) / 2, left, right);
	Node RNode = findMinNode(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return Node(min(LNode.minNode, RNode.minNode));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	init(1, 0, N - 1);

	int M; cin >> M;
	for (int i = 0; i < M; i++)
	{
		int cmd; cin >> cmd;
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
			Node ansNode = findMinNode(1, 0, N - 1, start - 1, end - 1);
			cout << ansNode.minNode << "\n";
		}
	}
	return 0;
}