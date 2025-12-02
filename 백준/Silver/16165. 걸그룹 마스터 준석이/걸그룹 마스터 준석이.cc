#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

int main()
{
	int N, M; cin >> N >> M;
	map<string, set<string>> idol;
	for (int i = 0; i < N; i++)
	{
		string group_name; cin >> group_name;
		int head_count; cin >> head_count;

		for (int cnt = 0; cnt < head_count; cnt++)
		{
			string name; cin >> name;
			idol[group_name].insert(name);
		}
	}

	for (int i = 0; i < M; i++)
	{
		string name; cin >> name;
		int cmd; cin >> cmd;
		if (cmd == 1){for (auto m : idol){if (m.second.find(name) != m.second.end()){cout << m.first << "\n";	break;}}}
		else{for (auto m : idol){if (m.first == name){for (auto s : m.second){cout << s << "\n";}break;}}}
	}

	return 0;
}