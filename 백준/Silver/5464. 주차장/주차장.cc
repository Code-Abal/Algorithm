#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int T;
	//cin >> T;
	for (int tc = 1; tc <= 1; tc++)
	{
		int N, M;
		cin >> N >> M;

		vector<int> fee(N + 1);
		vector<int> ton(M + 1);

		for (int i = 1; i <= N; i++)
		{
			cin >> fee[i];
		}

		for (int i = 1; i <= M; i++)
		{
			cin >> ton[i];
		}

		queue<int> q;
		
		for (int i = 0; i < M * 2; i++)
		{
			int temp; cin >> temp;
			q.push(temp);
		}

		vector<int> parking(N + 1, 0);
		vector<bool> visitcomplete(M + 1, false);
		int margin = 0;
		while (!q.empty())
		{
			int log = q.front();
			int in = 0, out = 0;
			if (log < 0)
			{
				out = log * -1; //출차

				//주차공간에서 차량넘버 찾는.
				for (int i = 1; i <= N; i++)
				{ 
					//최종적으로 주차&출차 여부 판별 후 아직 처리되지 않은 웨이팅이면 수행.
					if (parking[i] == out && !visitcomplete[out])
					{
						margin += fee[i] * ton[out];
						parking[i] = 0;
						visitcomplete[out] = true;
						break;
					}
				}
				//모든 차량은 주차&출차를 한다는 조건에 따라
				//출차의 경우 무조건 나감 -> 정산을 했느냐 안했느냐 처리가 중요함.
				q.pop();
			}
			else
			{
				in = log; //주차
				bool parkingTF = false;
				//빈 주차공간 찾는.
				for (int i = 1; i <= N; i++)
				{
					if (parking[i] == 0)
					{
						parking[i] = in;
						parkingTF = true;
						q.pop();
						break;
					}
				}
				//주차공간이 없어서 현재 큐를 복사해서 출차부터 찾음.
				if (!parkingTF)
				{
					queue<int> outq = q;
					int tempout = 0;
					while (!outq.empty())
					{
						tempout = outq.front();
						outq.pop();
						if (tempout < 0)
						{
							tempout *= -1;
							bool complete = false; //출차여부 판별
							for (int i = 1; i <= N; i++)
							{
								if (parking[i] == tempout)
								{
									margin += fee[i] * ton[tempout];
									parking[i] = 0;
									complete = true;
									visitcomplete[tempout] = true; //최종적으로 주차&출차 여부 판별
									break;
								}
							}
							//출차하면 종료.
							if (complete)
							{
								break;
							}
						}
					}
				}
			}
		}
		cout << margin;
	}
	return 0;
}  