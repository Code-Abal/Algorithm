#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

#define MAX_N 100000
#define MAX_INT INT32_MAX
#define MIN_INT INT32_MIN
typedef long long ll;

struct Frog
{
	ll curX, curY, curIdx;
	Frog() : curX(-1), curY(-1), curIdx(-1) {}
}frog;

map<ll, set<pair<ll, int>>> cross_left_to_down, cross_right_to_up;
vector<ll> flower_x(MAX_N), flower_y(MAX_N);
queue<char> dir_cmd;
int N, K;

void Init();
void LetsGo();
void Jump(char dir, ll frog_cur_x, ll frog_cur_y, ll frog_cur_dix);

void Init()
{
	cin >> N >> K;
	// 방향 값 char형
	for (int i = 0; i < K; i++)
	{
		char temp; cin >> temp;
		dir_cmd.push(temp);
	}
	
	// 개구리의 시작점.
	cin >> flower_x[0] >> flower_y[0];
	frog.curX = flower_x[0];
	frog.curY = flower_y[0];
	frog.curIdx = 0;
	cross_right_to_up[flower_x[0] + flower_y[0]].insert({ flower_x[0], 0 });
	cross_left_to_down[flower_x[0] - flower_y[0]].insert({ flower_x[0], 0 });

	for (int i = 1; i < N ; i++) 
	{
		cin >> flower_x[i] >> flower_y[i];
		cross_right_to_up[flower_x[i] + flower_y[i]].insert({ flower_x[i], i });
		cross_left_to_down[flower_x[i] - flower_y[i]].insert({ flower_x[i], i });
	}

	#pragma region 수정사항
	/*vector -> set으로 변경, 삭제 때문.
	set은 자동 오름차순, 이진 탐색을 사용하기 위한 사전 정렬이 필요 없음.*/

	//for (auto& a : cross_right_to_up) sort(a.second.begin(), a.second.end());
	//for (auto& a : cross_left_to_down) sort(a.second.begin(), a.second.end());
	#pragma endregion
}

void LetsGo()
{
	while (!dir_cmd.empty())
	{
		char dir = dir_cmd.front(); dir_cmd.pop();
		Jump(dir, frog.curX, frog.curY, frog.curIdx);
	}
}

void Jump(char dir, ll frog_cur_x, ll frog_cur_y, ll frog_cur_dix)
{
	int frog_next_idx = -1;

	if (dir == 'A') 
	{
		ll diff = frog_cur_x - frog_cur_y;
		auto& set = cross_left_to_down[diff];
		auto it = set.upper_bound({ frog_cur_x, MAX_INT });
		if (it != set.end())
		{
			frog_next_idx = it->second;
			frog.curX = it->first;
			frog.curY = flower_y[frog_next_idx];
			frog.curIdx = frog_next_idx;
		}
	}
	else if (dir == 'B') 
	{
		ll sum = frog_cur_x + frog_cur_y;
		auto& set = cross_right_to_up[sum];
		auto it = set.upper_bound({ frog_cur_x, MAX_INT });
		if (it != set.end())
		{
			frog_next_idx = it->second;
			frog.curX = it->first;
			frog.curY = flower_y[frog_next_idx];
			frog.curIdx = frog_next_idx;
		}
	}
	else if (dir == 'C') 
	{
		ll sum = frog_cur_x + frog_cur_y;
		auto& set = cross_right_to_up[sum];
		auto it = set.lower_bound({ frog_cur_x, MIN_INT });
		if (it != set.begin())
		{
			--it;
			frog_next_idx = it->second;
			frog.curX = it->first;
			frog.curY = flower_y[frog_next_idx];
			frog.curIdx = frog_next_idx;
		}
	}
	else if (dir == 'D') 
	{
		ll diff = frog_cur_x - frog_cur_y;
		auto& set = cross_left_to_down[diff];
		auto it = set.lower_bound({ frog_cur_x, MIN_INT });
		if (it != set.begin())
		{
			--it;
			frog_next_idx = it->second;
			frog.curX = it->first;
			frog.curY = flower_y[frog_next_idx];
			frog.curIdx = frog_next_idx;
		}
	}

	if (frog_next_idx != -1)
	{
		cross_left_to_down[frog_cur_x - frog_cur_y].erase({ frog_cur_x, frog_cur_dix });
		cross_right_to_up[frog_cur_x + frog_cur_y].erase({ frog_cur_x, frog_cur_dix });
	}
}

int main()
{
	Init();
	LetsGo();
	cout << frog.curX << " " << frog.curY;
	return 0;
}