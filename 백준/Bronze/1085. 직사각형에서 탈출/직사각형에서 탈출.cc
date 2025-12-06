#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int x, y, w, h; cin >> x >> y >> w >> h;

	int ans = min(min(abs(x - w), abs(y - h)), min(x, y));

	cout << ans;

	return 0;
}