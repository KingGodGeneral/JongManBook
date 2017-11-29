#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> cases;
vector<int> pSum;
vector<int> d, p, memo;
const int MOD = 20091101;
const int INF = 1000000;

vector<int> partialSum(const vector<int>& a) {
	vector<int> ret(a.size()+1);
	ret[0] = 0;
	for (int i = 1; i < a.size() + 1; i++) {
		ret[i] = (ret[i - 1] + a[i-1]) % k;
	}
	return ret;
}
int waysToBuy() {
	int ret = 0;
	vector<long long> count(k, 0);
	for (int i = 0; i < pSum.size(); ++i) {
		count[pSum[i]]++;
	}
	for (int i = 0; i < k; ++i) {
		if (count[i] >= 2) {
			ret = (ret + (count[i] * (count[i] - 1)) / 2) % MOD;
		}
	}
	return ret;
}
int maxBuys() {
	vector<int> ret(pSum.size(), 0);
	vector<int> prev(k, -1);

	for (int i = 0; i < pSum.size(); ++i) {
		if (i > 0)
			ret[i] = ret[i - 1];
		else
			ret[i] = 0;
		int loc = prev[pSum[i]];
		if (loc != -1) ret[i] = max(ret[i], ret[loc] + 1);
		prev[pSum[i]] = i;
	}
	return ret.back();
}
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int T; cin >> T;
	while (T--) {
		cin >> n >> k;
		cases.assign(n, 0);
		d.assign(n, -1);
		p.assign(n, -1);
		memo.assign(n, -1);
		for (int i = 0; i < n; i++) {
			cin >> cases[i];
		}
		pSum = partialSum(cases);
		int ans = waysToBuy();
		int ansB = maxBuys();
		cout << ans << ' ' << ansB << '\n';

	}
	return 0;
}