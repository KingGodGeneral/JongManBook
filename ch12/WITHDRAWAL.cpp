#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> r,c;

bool decision(double x) {
	vector<double> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = x*c[i] - r[i];
	}
	sort(v.begin(), v.end());
	double sum = 0;
	for (int i = 0; i < k; i++) {
		sum += v[n - i - 1];
	}
	return sum >= 0;
}

double optimize() {
	double lo = -0.1;
	double hi = 1.1;
	for (int i = 0; i < 50; i++) {
		double mid = (lo + hi) / 2;
		if (decision(mid)) {
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
	cout << fixed;
	cout.precision(10);
	while (T--) {
		cin >> n >> k;
		r.assign(n, 0);
		c.assign(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> r[i] >> c[i];
		}
		
		cout << optimize() << '\n';
	}
	return 0;
}