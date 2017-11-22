#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int n;
//두 기지 사이의 거리를 미리 계산한다.
double dist[101][101];
//거리 d이하인 기지들만을 연결했을 때 모든 기기가 연결되는지 여부를 반환한다.
bool decision(double d) {
	vector<bool> visited(n, false);
	visited[0] = true;
	queue<int> q;
	q.push(0);
	int seen = 0;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		++seen;
		for (int there = 0; there < n; ++there) {
			if (!visited[there] && dist[here][there] <= d) {
				visited[there] = true;
				q.push(there);
			}
		}
	}
	return seen == n;
}
//모든 기지를 연결할 수 있는 최소의 d를 반환한다.
double optimize() {
	double lo = 0, hi = 1416.00;
	for (int it = 0; it < 100; ++it) {
		double mid = (lo + hi) / 2;
		//mid가 가능하다면, 더 좋은 (작은) 답을 찾는다.
		if (decision(mid)) hi = mid;
		else lo = mid;
	}
	return hi;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T; cin >> T;
	while (T--) {
		cin >> n; 
		vector<pair<double, double>> coordinates(n);
		for (int i = 0; i < n; i++) {
			cin >> coordinates[i].first >> coordinates[i].second;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = sqrt(pow(coordinates[i].first - coordinates[j].first, 2) + pow(coordinates[i].second - coordinates[j].second, 2));
			}
		}
		double ans = optimize();
		cout << fixed;
		cout.precision(2);
		cout << ans<<'\n';		
	}
	return 0;
}
