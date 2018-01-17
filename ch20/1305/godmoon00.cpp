#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    string s;
    cin >> n >> s;
    int matched = 1;
    int j = 0;
    for (int i=1; i<n; i++) {
        if (s[i] == s[j]) {
            if (j == matched - 1) {
                j = 0;
            }
            else {
                j++;
            }
        }
        else {
            if (s[0] == s[i]) {
                matched = i;
                i--;
            }
            else {
                matched = i + 1;
            }
            j = 0;
        }
    }
    cout << matched;
}
