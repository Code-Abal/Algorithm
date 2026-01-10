#include <iostream>
using namespace std;

typedef long long ll;

const int MAX_N = 100004;
ll arr[MAX_N];
ll seg_tree[MAX_N * 4];
int N, Q;

void init()
{
	cin >> N >> Q;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

void build_segtree(int node, int start, int end)
{
	if (start == end) seg_tree[node] = arr[start];
	else
	{
		build_segtree(node * 2, start, (start + end) / 2); // 왼쪽 노드
		build_segtree(node * 2 + 1, (start + end) / 2 + 1, end); // 오른쪽 노드
		seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1];
	}
}

ll section_sum(int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;
	if (left <= start && end <= right ) return seg_tree[node];

	ll lsum = section_sum(node * 2, start, (start + end) / 2, left, right);
	ll rsum = section_sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);

	return lsum + rsum;
}

void update(int node, int start, int end, int idx, ll val)
{
	if (idx < start || end < idx) return;
	if (start == end)
	{
		arr[idx] = val;
		seg_tree[node] = val;
		return;
	}
	update(node * 2, start, (start + end) / 2, idx, val);
	update(node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
	seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1];
}

void controller()
{
	for (int q = 0; q < Q; q++)
	{
		int range_start, range_end, idx;
		ll val; 
		cin >> range_start >> range_end >> idx >> val;

		if (range_start > range_end) swap(range_start, range_end);
		
        cout << section_sum(1, 0, N - 1, range_start - 1, range_end - 1) << "\n";
		update(1, 0, N - 1, idx - 1, val);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	init();
	build_segtree(1, 0, N - 1);
	controller();
	return 0;
}