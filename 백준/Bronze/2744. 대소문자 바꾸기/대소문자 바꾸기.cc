#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0; // 한 단어 입력(문제 입력 형식)

    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            // 소문자 -> 대문자
            s[i] = c - ('a' - 'A');
        } else if (c >= 'A' && c <= 'Z') {
            // 대문자 -> 소문자
            s[i] = c + ('a' - 'A');
        }
    }

    cout << s << '\n';
    return 0;
}