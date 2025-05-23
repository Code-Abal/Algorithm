#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int P; cin >> P;

		vector<int> student;

		int cnt = 0;
		for(int i = 0; i < 20; i++)
		{
			int high; cin >> high;
			student.push_back(high);

			//마지막 값 저장.
			int back = student.back();
			for (int i = 0; i < student.size() - 1; i++)
			{
				if (student[i] > back)
				{
					// 맨 뒤에서부터 1칸씩 뒤로 밀리는 과정.
					for (int A = student.size() - 1; A > i; A--)
					{
						student[A] = student[A - 1];
						cnt++;
					}
					//밀리는 과정완료 후 A위치시킴.
					student[i] = back;
					//1칸씩 뒤로 밀렸으니, 마지막 값 갱신 
					// ** 갱신 안하면 예제는 통과처럼 보일 수 있으나, 실제 정렬은 엉터리로 이루어짐.
					back = student.back();
				}
			}
		}
		cout << P << " " << cnt << "\n";
	}
	return 0;
}  