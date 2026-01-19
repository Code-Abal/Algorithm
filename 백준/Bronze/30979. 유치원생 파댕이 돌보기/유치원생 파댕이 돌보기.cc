#include <iostream>
using namespace std;

int main() 
{
	int time; cin >> time;
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int F; cin >> F;
		time -= F;
	}
	time <= 0 ? cout << "Padaeng_i Happy" : cout << "Padaeng_i Cry";
	return 0;
}