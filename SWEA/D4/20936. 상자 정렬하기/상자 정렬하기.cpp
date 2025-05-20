#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

void test(vector<int>& box, int N)
{
	for (int i = 1; i <= N + 1; i++)
	{
		cout << box[i] << " ";
	}
	cout << "\n";
}

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int N; cin >> N;
		vector<int> box(N + 2);
		vector<int> ans;

		int current_X_idx = 0;
		int foundval = 0;
		int K = 0;
		bool tf = true;
		for (int i = 1; i <= N; i++)
		{
			cin >> box[i];
			if (box[i] != i)
			{
				current_X_idx = i;
				tf = false;
			}
		}
		box[N + 1] = N + 1;

		//정렬이 되어있지 않은 인덱스(칸)값을 찾아서 X칸과 교환으로 시작하고 횟수 1회 증가.
		swap(box[current_X_idx], box[N + 1]);
		K++; 

		//모든 값이 정렬되어있으면 생략.
		if (tf)
		{
			cout << "0" << "\n\n";
			continue;
		}

		while (1)
		{
			//정렬이 되어있지 않다는 것을 처리했으니, 정렬을 위한 탐색.
			for (int i = 1; i <= N + 1; i++)
			{
				//현재 칸에 들어와야할 값을 찾으면 교환(선택정렬)하고, X의 위치를 교환했던 칸으로 이동. 
				if (box[i] == current_X_idx)
				{
					//test(box, N);
					swap(box[current_X_idx], box[i]);
					ans.push_back(current_X_idx);
					current_X_idx = i;
					K++;
				}
			}
			/*
			* 정렬여부를 탐색하고, 정렬되어있지 않으면 정렬을 위해 해당 인덱스(칸)값으로 X를 이동.
			* 구체적으로는 정렬되어있지 않은 상태에서, X의 위치(인덱스/칸)가 찾아야할 값과 동일한 경우
			* 무한루프가 발생하고, 방지하기 위함.
			*/ 
			bool sorted = true;
			for (int i = 1; i <= N + 1; i++)
			{
				if (box[i] != i)
				{
					swap(box[current_X_idx], box[i]);
					ans.push_back(current_X_idx);
					current_X_idx = i;
					K++;
					sorted = false; 
					break;
				}
			}
			
			/*
			if (!sorted)
			{
				for (int i = 1; i <= N + 1; i++)
				{
					if (box[i] == current_X_idx)
					{
						current_X_idx = i;
						ans.push_back(current_X_idx);
					}
				}
				
			}
			*/

			if (sorted)  break;
		}

		//마지막 되돌아오는 경로, 추가.
		ans.push_back(N + 1);
		
		cout << K << "\n";
		for (int i : ans)
		{
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}  
