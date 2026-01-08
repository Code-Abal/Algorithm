#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a, b;
	while (cin >> a >> b) {
		if (a == 0 && b == 0) break; // 종료 조건
		if (a > b) cout << "Yes\n";
		else       cout << "No\n";
	}
	return 0;
}