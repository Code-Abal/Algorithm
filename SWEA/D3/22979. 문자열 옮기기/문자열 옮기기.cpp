#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		string S; cin >> S;

		//문자형 배열로 변환.
		vector<char> arr;
		for (char c : S)
		{
			arr.push_back(c);
		}

		int sum_k = 0;
		int size = arr.size();
		int k; cin >> k;

		//최종 연산만 고려함.
		for (int i = 0; i < k; i++)
		{
			int temp; cin >> temp;
			sum_k += temp % size;
		}
		if (sum_k > 0)
		{
			for (int i = 0; i < sum_k; i++)
			{
				char front = arr.front();
				arr.push_back(front);
				arr.erase(arr.begin());
			}
		}
		else if (sum_k < 0)
		{
			//마지막 글자 저장 후, 인덱스를 1칸씩 증가시켜 첫 번째 글자 공간을 만듬.
			for (int i = 0; i < abs(sum_k); i++)
			{
				char back = arr.back();
				
				for (int i = arr.size() - 1; i >= 1; i--)
				{
					arr[i] = arr[i - 1];
				}
				arr[0] = back;
			}
		}

		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i];
		}
		cout << "\n";
	}

	return 0;
}  