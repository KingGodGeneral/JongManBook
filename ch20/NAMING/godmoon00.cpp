#include <bits/stdc++.h>

using namespace std;

vector<int> getPi(const string& N)
{
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (N[begin + matched] == N[matched]) {
            matched++;
            pi[begin + matched - 1] = matched;
        }
        else {
            if (matched == 0) {
                begin++;
            }
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    string n, h;
    cin >> n >> h;
    n += h;
    vector<int> pi = getPi(n), ans;
    int k = n.size();
    while (k > 0) {
        ans.push_back(k);
        k = pi[k - 1];
    }

    sort(ans.begin(), ans.end());
    for (auto& i: ans) {
        cout << i << ' ';
    }
}
