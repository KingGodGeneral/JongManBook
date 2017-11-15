#include <iostream>
#include <vector>
using namespace std;

//���� ����: ���ĵǾ��ִ� location �� camera�� ������ ��� ī�޶� ���� ������
//gap �̻��� �Ǵ� ����� �ִ����� ��ȯ�Ѵ�.
bool decision(const vector<double>& location, int cameras, double gap) {
	//ī�޶� ��ġ�� �� ���� ������ ��ġ�ϴ� Ž���� �˰���
	double limit = -1;
	int installed = 0;
	for (int i = 0; i < location.size(); ++i) {
		if (limit <= location[i]) {
			++installed;
			//location[i]+gap ���Ĵ� �Ǿ�� ī�޶� ��ġ�� �� �ִ�.
			limit = location[i] + gap;
		}
	}
	//��������� cameras�� �̻��� ��ġ�� �� �־����� ����
	return installed >= cameras;
}
double optimize(const vector<double>& location, int cameras) {
	double lo = 0, hi = 241;
	//�ݺ��� �Һ���: decision(lo)&& !decision(hi)
	for (int it = 0; it < 100; ++it) {
		double mid = (lo + hi) / 2.0;
		//������ mid �̻��� �ǵ��� �� �� ������ ���� [mid,hi]�� �ִ�.
		if (decision(location, cameras, mid)) 
			lo = mid;
		else 
			hi = mid;
	}
	return lo;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		vector<double> location(M);
		for (int i = 0; i < M; i++) {
			cin >> location[i];
		}
		double ans = optimize(location, N);
		cout << fixed;
		cout.precision(2);
		cout << ans << '\n';
	}
	return 0;
}