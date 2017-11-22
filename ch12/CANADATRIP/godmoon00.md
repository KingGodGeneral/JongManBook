- 수행시간: 52ms

`cout << mid` 로 했다가 여러번 틀렸는데 왜 `cout << low`로 해야하는지 아직 이해가 가지않음(내용추가 예정)

```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int low = 8030000, high = 0, mid;
        vector<vector<int>> v;
        for (int i=0; i<n; i++) {
            int l, m ,g;
            cin >> l >> m >> g;
            v.push_back({l, m, g});
            low = min(low, l - m);
            high = max(high, l);
        }
        while (low <= high) {
            mid = (low + high) / 2;
            long long cnt = 0;
            for (auto &i: v) {
                if (mid >= i[0] - i[1] && mid <= i[0]) {
                    cnt += (mid - (i[0] - i[1])) / i[2] + 1;
                }
                else if (mid > i[0]) {
                    cnt += i[1] / i[2] + 1;
                }
            }
            if (cnt < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        cout << low << '\n';
    }
}
```
