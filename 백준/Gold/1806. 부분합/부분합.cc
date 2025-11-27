#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100000

int arr[MAX_N];
int N, S;

void Init()
{
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

int TwoPointer()
{
	int min_len = MAX_N;
	int left = 0, right = 0;
	int sum = 0;

	while (right < N)
	{
		sum += arr[right];
		right++;

		while (sum >= S)
		{
			min_len = min(min_len, right - left);
			sum -= arr[left];
			left++;
		}
	}

	if (min_len == MAX_N) return 0;
	else return min_len;
}
int main()
{
	Init();
	cout << TwoPointer();
	return 0;
}