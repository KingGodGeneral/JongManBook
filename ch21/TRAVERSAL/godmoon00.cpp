/*
* 수행시간: 4ms
* 종만북 코드와 동일
* 비슷한 문제인 https://www.acmicpc.net/problem/2263 를 이 코드를 조금 수정하여 풀어봤으나 메모리 초과가 뜸. 이유를 알아볼것
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> Slice(const vector<int> &v, int a, int b)
{
    return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder)
{
    const int N = preorder.size();
    if (N == 0) return;

    const int root = preorder[0];
    const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();

    printPostOrder(Slice(preorder, 1, L + 1), Slice(inorder, 0, L));
    printPostOrder(Slice(preorder, L + 1, N), Slice(inorder, L + 1, N));
    cout << root << ' ';
}

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
        int n;
        cin >> n;
        vector<int> pre, in;
        for (int i=0; i<n; i++) {
            int temp;
            cin >> temp;
            pre.push_back(temp);
        }
        for (int i=0; i<n; i++) {
            int temp;
            cin >> temp;
            in.push_back(temp);
        }
        printPostOrder(pre, in);
        cout << '\n';
    }
}
