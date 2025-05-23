#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

//최대값 비교
int maxmoney = 0;

int change(string money, int cnt, int N, vector<bool>& visited)
{
	if (cnt == N)
	{
		maxmoney = max(maxmoney, stoi(money));
		return maxmoney;
	}

	for (int i = 0; i < money.length() - 1; i++)
	{
		for (int j = i + 1; j < money.length(); j++)
		{
			//교환여부 판별.
			//재귀함수 입장에서는 true값을 가진 상태로 진행.
			//다시 false값으로 변경하여, 다른 자리수에 영향을 주지 않도록 함.
			swap(money[i], money[j]); visited[i] = true;
			change(money, cnt + 1, N, visited);
			swap(money[j], money[i]); visited[i] = false;
		}
	}
	//최종결과값을 꼭 반환해줘야함.
	return maxmoney;
}

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		string money;
		int N;
		cin >> money >> N;
		int sort = 0;

		// 횟수가 가격자릿수보다 크면 마지막 2자리만 반복교환
		// 불필요한 교환횟수를 방지하고자 횟수를 제한함.
		if (money.length() < N)
		{
			sort = money.length();
		}
		else
		{
			sort = N;
		}

		int len = money.length();
		//재교환하는 횟수를 방지하고자 판별함.
		vector<bool> visited(len, false); 

		//전역변수 초기화,미 초기화시 중간에 큰 가격이 등장하게 되면 
		//다음 테스트케이스까지 같은 결과 출력됨.
		maxmoney = 0;

		//횟수에 따른 최대값을 반환받고, 
		//이전, 횟수에 따른 결과를 반영하기 위해 변환.
		string ans = to_string(change(money, 0, sort, visited));

		//남은 횟수가 짝수라면, 원상복구.
		//홀수일 경우에 교환이 성립되어야 하기 때문에
		//인덱스를 기준으로 마지막 2자리 서로 교환.
		if ((N - sort) % 2 != 0)
		{
			swap(ans[len - 2], ans[len - 1]);
		}

		int res = stoi(ans);
		cout << "#" << tc << " " << res << "\n";
	}
	return 0;
}  
