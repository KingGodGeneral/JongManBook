#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		vector<double> location(M);
		for (int i = 0; i < M; i++) {
			cin >> location[i];
		}
		vector<vector<double>> dp(M-1, vector<double>(N-1));
		for (int i = 0; i < M-1; i++) {
			dp[i][0] = location[M - 1] - location[i];
		}
		//dp[a][b] = location[a]�� ī�޶� ����, location[M-1]�� ī�޶� ����, 
		//�� ���̿� b���� ī�޶� ������ ��, ���� ����� �� ī�޶� �ִ� ���� 
		for (int i = 1; i < N-1; i++) {
			for (int j = 0; j < M-i-1; j++) {
				for (int p = j+1; p < M - i; p++) {
					dp[j][i] = max(dp[j][i], min(location[p] - location[j], dp[p][i - 1]));
				}
			}
		}		
		double ans = dp[0][N-2];
		cout << fixed;
		cout.precision(2);
		cout << ans << '\n';
	}
	return 0;
}