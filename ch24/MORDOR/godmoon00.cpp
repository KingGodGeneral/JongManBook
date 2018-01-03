#include <bits/stdc++.h>

using namespace std;

struct RMQ {
    // 배열의 길이
    int n;

    // 각 구간의 최소치
    vector<int> rangeMin;
    RMQ(const vector<int>& array)
    {
        n = array.size();
        rangeMin.resize(n * 4);
        init(array, 0, n-1, 1);
    }

    // node 노드가 array[left, right] 배열을 표현할 때
    // node 를 루트로 하는 서브트리를 초기화하고, 이 구간의 최소치를 반환한다.
    int init(const vector<int>& array, int left, int right, int node)
    {
        if (left == right) {
            return rangeMin[node] = array[left];
        }

        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid, node * 2);
        int rightMin = init(array, mid + 1, right, node * 2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }

    // node가 표현하는 범위 array[nodeLeft, nodeRight] 가 주어질 때
    // 이 범위와 array[left, right]의 교집합의 최소치를 구한다.
    int query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        // 두 구간이 겹치지 않으면 아주 큰 값을 반환한다
        if (right < nodeLeft || nodeRight < left) return 987654321;
        // node가 표현하는 범위가 array[left, right] 에 완전히 포함되는 경우
        if (left <= nodeLeft && nodeRight <= right) return rangeMin[node];
        // 양쪽 구간을 나눠서 푼 뒤 결과를 합친다.
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }

    int query(int left, int right)
    {
        return query(left, right, 1, 0, n-1);
    }
};

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
        int n, q;
        cin >> n >> q;
        vector<int> a1, a2;
        while(n--) {
            int h;
            cin >> h;
            a1.push_back(h);
            a2.push_back(-h);
        }
        RMQ MIN = a1;
        RMQ MAX = a2;
        while (q--) {
            int a, b;
            cin >> a >> b;
            cout << - MAX.query(a, b) - MIN.query(a, b) << '\n';
        }
    }
}
