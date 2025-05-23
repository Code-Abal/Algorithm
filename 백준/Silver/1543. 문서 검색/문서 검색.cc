#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	//int T;
	//cin >> T;
	for (int tc = 1; tc <= 1; tc++)
	{
		//공백포함 입력받기.
		string str; getline(cin, str);
		string findstr; getline(cin, findstr);

		int cnt = 0;
		while (str.length() >= findstr.length())
		{
			for (int i = 0; i <= str.length() - findstr.length(); i++)
			{
				bool copy = true;
				//찾아야하는 인덱스는 유지하고, 원문인덱스에 증가시켜 접근.
				for (int j = 0; j < findstr.length(); j++)
				{
					int ni = i + j;
					if (str[ni] != findstr[j])
					{
						copy = false;
						break;
					}
				}
				if (copy)
				{
					//str.erase(str.begin() + i , str.begin() + i + findstr.length());
					cnt++;
					i += findstr.length() - 1;
					//break;
				}
			}
			break;
		}
		cout << cnt;
	}
	return 0;
}  