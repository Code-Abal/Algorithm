#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100000
#define MAX_INT INT32_MAX
#define MIN_INT INT32_MIN

struct Node
{
	long long minNode, maxNode;
	Node() : minNode(MAX_INT), maxNode(MIN_INT) {} // 기본 생성자
	Node(long long leafNode) : minNode(leafNode), maxNode(leafNode) {} // 단일 노드일 때 최소, 최대 초기화
	Node(long long _minNode, long long _maxNode) : minNode(_minNode), maxNode(_maxNode) {} // 최솟값과 최대값을 알고 있을 경우, 초기화
};

long long arr[MAX_N];
Node tree[MAX_N * 4];

void init(int node, int start, int end);
long long sectionSum(int node, int start, int end, int left, int right);
void update(int node, int start, int end, int index, long long val);

void init(int node, int start, int end)
{
	if (start == end) tree[node] = Node(arr[start]);
	else
	{
		init(node * 2, start, (start + end) / 2); // 왼쪽 노드
		init(node * 2 + 1, (start + end) / 2 + 1, end); // 오른쪽 노드
		tree[node] = Node(min(tree[node * 2].minNode, tree[node * 2 + 1].minNode), max(tree[node * 2].maxNode, tree[node * 2 + 1].maxNode));
	}
}

Node FindMinMax(int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return Node(); 
	if (left <= start && end <= right) return tree[node]; 

	Node LNode = FindMinMax(node * 2, start, (start + end) / 2, left, right);
	Node RNode = FindMinMax(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	long long minNode = min(LNode.minNode, RNode.minNode);
	long long maxNode = max(LNode.maxNode, RNode.maxNode);

	return Node(minNode, maxNode);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> arr[i];

	init(1, 0, N - 1);// 트리 초기화 init(루트노드, 시작 인덱스, 끝 인덱스)

	for (int i = 0; i < M; i++)
	{
		long long a, b;
		cin >> a >> b;
		Node ans = FindMinMax(1, 0, N - 1, a - 1, b - 1);
		cout << ans.minNode << " " << ans.maxNode << "\n";										
	}
	return 0;
}