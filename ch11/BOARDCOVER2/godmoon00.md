- 수행 시간: 912ms

```cpp
#include <bits/stdc++.h>

using namespace std;

bool board[10][10];
set<set<pair<int, int>>> s;
int h, w, r, c;
int ans;
int numPuzzle;
int numWhite;

void go(int n, int m, int cnt)
{
    if (cnt + numWhite / numPuzzle <= ans) return;
    if (m == w) {
        n = n + 1;
        m = 0;
    }
    if (n == h || numWhite < numPuzzle) {
        ans = max(ans, cnt);
        return;
    }
    if (!board[n][m]) numWhite--;
    go(n, m + 1, cnt);
    if (!board[n][m]) numWhite++;
    for (auto &i: s) {
        bool check = true;
        for (auto &j: i) {
            int x = n + j.first;
            int y = m + j.second;
            if (x < 0 || x >= h || y < 0 || y >= w || board[x][y]) {
                check = false;
                break;
            }
        }
        if (check) {
            for (auto &j: i) {
                int x = n + j.first;
                int y = m + j.second;
                board[x][y] = true;
                numWhite--;
            }
            go(n, m + 1, cnt + 1);
            for (auto &j: i) {
                int x = n + j.first;
                int y = m + j.second;
                board[x][y] = false;
                numWhite++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ans = 0;
        numPuzzle = 0;
        s.clear();
        memset(board, false, sizeof(board));
        cin >> h >> w >> r >> c;
        numWhite = h * w;
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                char ch;
                cin >> ch;
                if (ch == '#') {
                    board[i][j] = true;
                    numWhite--;
                }
            }
        }

        set<pair<int, int>> temp1, temp2, temp3, temp4;
        for(int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                char ch;
                cin >> ch;
                if (ch == '#') {
                    temp1.insert({i ,j});
                    numPuzzle++;
                }
            }
        }
        for (auto &i: temp1) {
            temp2.insert({-i.second + c - 1, i.first});
            temp3.insert({-i.first + r - 1, -i.second + c - 1});
            temp4.insert({i.second,-i.first + r - 1});
        }
        s.insert(temp1);
        s.insert(temp2);
        s.insert(temp3);
        s.insert(temp4);
        go(0, 0, 0);
        cout << ans << '\n';
    }
}
```
