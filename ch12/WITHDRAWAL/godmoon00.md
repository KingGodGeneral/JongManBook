- 수행시간: 36ms

```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int r[1000], c[1000];
        for (int i=0; i<n; i++) {
            cin >> r[i] >> c[i];
        }
        double low = 0, high = 1, mid;
        while (high - low > 1e-10) {
            mid = (low + high) / 2;
            vector<double> v;
            for (int i=0; i<n; i++) {
                v.push_back(mid * c[i]- r[i]);
            }
            sort(v.begin(), v.end(), greater<double>());
            double sum = 0;
            for (int i=0; i<k; i++) {
                sum += v[i];
            }
            if (sum >= 0) {
                high = mid;
            }
            else {
                low = mid;
            }
        }
        cout << fixed << setprecision(10) << high << '\n';
    }
}
```
