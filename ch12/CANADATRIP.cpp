#include <iostream>
#include <vector>
using namespace std;

int N, K;

//x위치에서 보는 표지판이 K개 이상이면 true
bool decision(const vector<vector<int>>& ar, int x) {
	int seen = 0;
	for (int i = 0; i < ar.size(); i++) {
		int cd = ar[i][0] - ar[i][1];
		if (cd <= x) {
			if (ar[i][0] >= x) {
				seen += (x - cd) / ar[i][2] + 1;
			}
			else {
				seen += (ar[i][0] - cd) / ar[i][2] + 1;
			}
		}
	}
	return seen>=K;
}

int optimize(const vector<vector<int>>& ar) {
	int lo = 0, hi = 8030001;
	for (int i = 0; i < 100; i++) {
		int mid = (lo + hi+1)/ 2;
		if (decision(ar, mid)) {
			hi = mid;
		}
		else {
			lo = mid;
		}
	}
	return hi;
}
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T; cin >> T;
	while (T--) {
		cin >> N >> K;
		vector<vector<int>> ar(N, vector<int>(3));
		for (int i = 0; i < N; i++) {
			cin >> ar[i][0] >> ar[i][1] >> ar[i][2];
		}
		int ans = optimize(ar);
		cout << ans << '\n';
	}
	return 0;
}