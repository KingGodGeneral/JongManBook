- 수행 시간: 24ms

인접행렬 + BFS 이용

기지간 거리가 통신 반경 이하일 경우 연결되어있다고 생각하고 

어떤 통신 반경 x에 대해 BFS로 탐색했을시 모든 정점이 연결되어있으면 -> x가 작아져도 됨

연결되어있지 않으면 -> x가 커져야 함

```cpp
#include <bits/stdc++.h>

using namespace std;

double getDis(double x, double y)
{
    return x * x + y * y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    while (c--) {
        vector<pair<double, double>> v;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }
        double dis[100][100];
        double MIN = 1000000;
        double MAX = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dis[i][j] = getDis(v[i].first - v[j].first, v[i].second - v[j].second);
                MIN = min(MIN, dis[i][j]);
                MAX = max(MAX, dis[i][j]);
            }
        }
        double ans = 1000000;
        while(abs(MAX - MIN) > 1e-6) {
            double MID = (MIN + MAX) / 2;
            bool check[100] {};
            queue<int> q;
            check[0] = true;
            q.push(0);
            int cnt = 1;
            while (!q.empty()) {
                int now = q.front();
                q.pop();
                for (int i=0; i<n; i++) {
                    if (dis[now][i] <= MID && !check[i]) {
                        cnt++;
                        q.push(i);
                        check[i] = true;
                    }
                }
            }
            if (cnt == n) {
                MAX = MID;
                ans = min(ans, MID);
            }
            else {
                MIN = MID;
            }
        }
        cout << fixed<< setprecision(2) << sqrt(ans) << '\n';
    }
}
```
