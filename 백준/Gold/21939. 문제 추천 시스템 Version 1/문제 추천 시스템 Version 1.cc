#include <iostream>
#include <string>	
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

struct cmp
{
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) const
	{
		if (a.second == b.second) return a.first < b.first;
		return a.second < b.second;
	}
};

multimap<pair<int, int>, int, cmp> unmap;
unordered_map<int, int> problem;
void init();
void controll();

void init()
{
	// key = 난이도(L) / value = 문제번호(P)
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int P, L;
		cin >> P >> L;
		unmap.emplace(make_pair(P, L), 0);
		problem[P] = L;
	}
}

void controll()
{
	int M; cin >> M;
	// key = 난이도(L) / value = 문제번호(P)
	for (int i = 0; i < M; i++)
	{
		string cmd; cin >> cmd;
		if (cmd == "add")
		{
			int P, L;
			cin >> P >> L;
			unmap.emplace(make_pair(P, L), 0);
		}
		else if (cmd == "recommend")
		{
			int x; cin >> x;
			if (x == 1) cout << prev(unmap.end())->first.first << "\n";
			else cout << unmap.begin()->first.first<< "\n";
		}
		else if (cmd == "solved")
		{
			int P; cin >> P;
			int value = problem[P];
			unmap.erase({ P, value });
			problem.erase(P);
		}
	}
}

int main()
{
	init();
	controll();
	return 0;
}