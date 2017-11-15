- 수행 시간: 4ms

`간격을 최대화` 한다 -> `간격`을 기준으로 이분탐색.

간격의 최솟값은 0, 최댓값은 카메라가 있을 수 있는 거리 중 가장 먼 거리

만약 간격 x이상으로 카메라를 둘 때 놓을수 있는 카메라의 수가 n이상이면 -> 간격을 늘려도됨

n 미만이면 -> 간격을 줄여야함

while문을 돌면서 MIN과 MAX의 차이가 매우 작아질때까지 반복한다. (정수 이분탐색과 다른 점)

그리고 간격의 최댓값을 물어봤으므로 MID의 max값을 출력하면 끝

```cpp
#include <bits/stdc++.h>

using namespace std;

int n, m;
double arr[200];

bool check(double x)
{
    int cnt = 1;
    double prev = arr[0];
    for (int i=1; i<m; i++) {
        if ((arr[i] - prev) >= x ) {
            cnt++;
            prev = arr[i];
        }
    }
    return cnt >= n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    while (c--) {
        cin >> n >> m;
        double MIN = 240, MAX = 0;
        for (int i=0; i<m; i++) {
            cin >> arr[i];
            MIN = min(arr[i], MIN);
            MAX = max(arr[i], MAX);
        }
        MAX = MAX - MIN;
        MIN = 0;
        double ans = 0;
        while(abs(MIN - MAX) > 1e-6) {
            double MID = (MIN + MAX) / 2;
            if (check(MID)) {
                MIN = MID;
                ans = max(ans, MID);
            }
            else {
                MAX = MID;
            }
        }
        cout << fixed << setprecision(2) << ans << '\n';
    }
}
```
