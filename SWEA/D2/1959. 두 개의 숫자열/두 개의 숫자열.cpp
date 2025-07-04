#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		cin >> N >> M;
        
		vector<int> Aarr(N);
		vector<int> Barr(M);

		for (int i = 0; i < N; i++) cin >> Aarr[i];
		for (int i = 0; i < M; i++) cin >> Barr[i];
		
		int max = 0;
		if (M > N)
		{
			for (int i = 0; i <= M - N; i++)
			{
				int sum = 0;
				for (int j = 0; j < N; j++) sum += Aarr[j] * Barr[j + i];
				if (sum > max) max = sum;
			}
		}
		else
		{
			for (int i = 0; i <= N - M; i++)
			{
				int sum = 0;
				for (int j = 0; j < M; j++) sum += Barr[j] * Aarr[j + i];
				if (sum > max) max = sum;
			}
		}
		cout << "#" << test_case << " " << max << "\n";
	}
	return 0;
}