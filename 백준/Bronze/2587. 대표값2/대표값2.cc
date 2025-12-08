#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a(5);
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin(), a.end());
    cout << (sum / 5) << "\n";
    cout << a[2] << "\n";

    int freq[101] = {0}; 
    for (int v : a) ++freq[v];

    int mode = 0;
    int maxCnt = 0;
    for (int val = 0; val <= 100; ++val) {
        if (freq[val] > maxCnt) {
            maxCnt = freq[val];
            mode = val;
        }
    }
    return 0;
}