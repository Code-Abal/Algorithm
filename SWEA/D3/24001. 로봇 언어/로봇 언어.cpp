#include <iostream>
#include <vector>

using namespace std;

int BASE = 100;
int Robot(vector<char>& cmd, int idx, int pos, vector<vector<int>>& abspos)
{
	if (idx == cmd.size())
	{
		return abs(pos);
	}

	if (abspos[idx][pos + BASE] != -1)
	{
		return abspos[idx][pos + BASE];
	}

	if (cmd[idx] == 'L')
	{
		abspos[idx][pos + BASE] = Robot(cmd, idx + 1, pos - 1, abspos);
	}
	else if (cmd[idx] == 'R')
	{
		abspos[idx][pos + BASE] = Robot(cmd, idx + 1, pos + 1, abspos);
	}
	else
	{
		int Letf = Robot(cmd, idx + 1, pos - 1, abspos);
		int Right = Robot(cmd, idx + 1, pos + 1, abspos);
		abspos[idx][pos + BASE] = max(Letf, Right);
	}

	abspos[idx][pos + BASE] = max(abs(pos), abspos[idx][pos + BASE]);
	return abspos[idx][pos + BASE];
}

int main()
{
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		string str; cin >> str;

		vector<char> cmd;
		for (char c : str)
		{
			cmd.push_back(c);
		}
		
		vector<vector<int>> abspos(51, vector<int>(151, -1));
		
		cout << Robot(cmd, 0, 0, abspos) << "\n";
	}

	return 0;
}