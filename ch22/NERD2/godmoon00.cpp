#include <bits/stdc++.h>

using namespace std;

// m[x] = y
map<int, int> m;
// 새 점 (x, y) 가 이미 포함되었는지 아닌지 확인
// (x, y) 바로 오른쪽에 있는 점의 높이가 더 높으면 이미 포함, 아니면 포함 X
bool isDominated(int x, int y)
{
    auto it = m.lower_bound(x);
    // (x, y) 가 가장 오른쪽일 경우
    if (it == m.end()) return false;
    return y < it -> second;
}

// 새 점 (x, y) 가 지배하는 점들을 제거
// 왼쪽에서 가장 가까운 점에서부터 시작하여 (x, y) 보다 높이가 낮다면 제거한다.
void removeDominated(int x, int y)
{
    auto it = m.lower_bound(x);
    // 왼쪽에 점이 없을 경우
    if (it == m.begin()) return;
    it--;
    while(it -> second <= y) {
        if (it == m.begin()) {
            m.erase(it);
            break;
        }
        else {
            it = m.erase(it);
            it--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, ans = 0;
        cin >> n;
        m.clear();
        while (n--) {
            int x, y;
            cin >> x >> y;
            // 만약 (x, y) 가 지배되지 않는다면
            // (x, y) 에 의해 지배되는 점들을 지우고 (x, y) 추가
            // (x, y) 가 지배된다면 무시
            if (!isDominated(x, y)) {
                removeDominated(x, y);
                m[x] = y;
            }
            ans += m.size();
        }
        cout << ans << '\n';
    }
}
