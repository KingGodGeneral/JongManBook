#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int n;
//�� ���� ������ �Ÿ��� �̸� ����Ѵ�.
double dist[101][101];
//�Ÿ� d������ �����鸸�� �������� �� ��� ��Ⱑ ����Ǵ��� ���θ� ��ȯ�Ѵ�.
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
//��� ������ ������ �� �ִ� �ּ��� d�� ��ȯ�Ѵ�.
double optimize() {
	double lo = 0, hi = 1416.00;
	for (int it = 0; it < 100; ++it) {
		double mid = (lo + hi) / 2;
		//mid�� �����ϴٸ�, �� ���� (����) ���� ã�´�.
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
