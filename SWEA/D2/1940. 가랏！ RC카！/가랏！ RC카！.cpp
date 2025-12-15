#include<iostream>

using namespace std;

int main()
{
	int test_case;
	int T; cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N; cin >> N;

		int speed = 0;
		int distance = 0;

		for (int i = 0; i < N; i++)
		{
			int command, value;
			cin >> command;

			if (command != 0) cin >> value;

			switch (command)
			{
			case 1:
			{
				speed += value;
				distance += speed;
				break;
			}
			case 2:
			{
				if (speed <= value) speed = 0;
				else speed -= value;
				distance += speed;
				break;
			}
			case 0:
			{
				distance += speed;
				break;
			}
			}
		}
		cout << "#" << test_case << " " << distance << "\n";
	}
	return 0;
}