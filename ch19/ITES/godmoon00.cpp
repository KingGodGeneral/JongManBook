#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_DUGDE
    freopen("input.txt", "r", stdin);
#endif

    int c;
    cin >> c;
    while (c--) {
        int k, n, ans = 0;
        cin >> k >> n;
        queue<int> q;
        q.push(0);
        long long a, prev = 0, sum = 0;
        while (n) {
            if (sum > k) {
                sum -= q.front();
                q.pop();
            }
            else if (sum == k) {
                sum -= q.front();
                q.pop();
                ans++;
            }
            else {
                if (prev == 0) {
                    a = 1983;
                }
                else {
                    a = (prev * 214013 + 2531011) % (1LL<<32);
                }
                prev = a;
                q.push(a%10000+1);
                sum += a%10000+1;
                n--;
            }
        }
        cout << ans << '\n';
    }
}
