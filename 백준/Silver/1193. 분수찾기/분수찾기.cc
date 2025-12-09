#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    if (!(cin >> n)) return 0;
    
    // d: 대각선 번호 (1부터 시작), prevSum = 1..(d-1) 합 = (d-1)*d/2
    // d*(d+1)/2 >= n 인 최소의 d를 찾음
    long long d = (long long)((sqrt(8.0*n + 1) - 1) / 2); // 근사값
    // 보정: 위 식은 floor가 될 수 있으므로 보정
    while (d * (d + 1) / 2 < n) ++d;
    while ((d - 1) * d / 2 >= n) --d;
    
    long long prevSum = (d - 1) * d / 2;
    long long pos = n - prevSum; // 대각선 d 안에서의 위치 (1-based)
    
    long long num, den;
    if (d % 2 == 0) {
        // 짝수 대각선: 분자가 pos 증가, 분모는 d+1-pos
        num = pos;
        den = d + 1 - pos;
    } else {
        // 홀수 대각선: 분자가 d+1-pos, 분모는 pos
        num = d + 1 - pos;
        den = pos;
    }
    
    cout << num << '/' << den << '\n';
    return 0;
}