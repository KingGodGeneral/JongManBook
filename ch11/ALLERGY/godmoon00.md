- 수행시간: 8ms

```cpp
#include <bits/stdc++.h>

using namespace std;
vector<int> v[50]; // 친구 i가 먹을 수 있는 음식들
vector<int> v2[50]; // 음식 i를 먹을 수 있는 친구들

int ans;

void go(vector<int> cant, int cnt)
{
    if (cnt >= ans) return;
    if (cant.empty()) {
        ans = cnt;
        return;
    }
    int MIN = cant[0];
    for (auto &i: cant) {
        if (v[i].size() < v[MIN].size()) MIN = i;
    }

    for (auto &food: v[MIN]) {
        vector<int> temp;
        for (auto &i: cant) {
            if (find(v[i].begin(), v[i].end(), food) == v[i].end()) {
                temp.push_back(i);
            }
        }
        go(temp, cnt + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ans = 50;
        for (int i=0; i<50; i++) {
            v[i].clear();
            v2[i].clear();
        }
        int n, m;
        cin >> n >> m;
        map<string, int> friends;
        for (int i=0; i<n; i++) {
            string s;
            cin >> s;
            friends[s] = i;
        }
        for (int i=0; i<m; i++) {
            int num;
            cin >> num;
            for (int j=0; j<num; j++) {
                string s;
                cin >> s;
                v2[i].push_back(friends[s]);
                v[friends[s]].push_back(i);
            }
        }
        vector<int> cant;
        for (int i=0; i<n; i++) {
            cant.push_back(i);
        }
        go(cant, 0);
        cout << ans << '\n';
    }
}
```
