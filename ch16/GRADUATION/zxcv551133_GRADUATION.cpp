#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//N: ���������� ��, K: ������ ������ ��, M: �б��� ��, L: ���б⿡ �ִ�� ���� �� �ִ� ������ ��
int N, K, M, L;
vector<int> prerequisite;		//Ư�� ���� �䱸�Ǵ� ���������
vector<int> classes;			//Ư�� �б⿡ ������ �����
vector<vector<int>> memo;		//�����б���� �̷��� �������� �� �ʿ��� �б� ��
const int INF = 9999999;

int bitCount(int n) {
	if (n == 0) return 0;
	return bitCount(n / 2) + n % 2;
}
//
int isPossible(int semester, int taken) {
	//K���̻��� �� ���� ���
	if (bitCount(taken) >= K) return 0;
	//���� ���: M�бⰡ ���� ���� ���
	if (semester == M) return INF;
	//�޸������̼�
	int& ret = memo[semester][taken];
	if (ret != -1) return ret;

	ret = INF;

	int canTake = classes[semester] & ~taken;

	for (int i = 0; i < N; i++) {
		if ((canTake & (1 << i)) && (prerequisite[i] & taken) != prerequisite[i])
			canTake &= ~(1 << i);
	}	
	for (int take = canTake; take > 0; take = (take - 1)& canTake) {
		if (bitCount(take) > L) continue;
		ret = min(ret, isPossible(semester + 1, taken | take) + 1);
	}
	//�̹��б⿡ �ƹ��͵� �������� ���
	ret = min(ret, isPossible(semester + 1, taken));
	return ret;
}

int main() {
	int C; cin >> C;
	while (C--) {
		cin >> N >> K >> M >> L;
		prerequisite.assign(N, 0);
		memo.assign(M, vector<int>(1 << N,-1));
		classes.assign(M, 0);
		for (int i = 0; i < N; i++) {
			int r; cin >> r;
			while(r--) {
				int index; cin >> index;
				prerequisite[i] |= 1 << index;
			}
		}
		for (int i = 0; i < M; i++) {
			int c; cin >> c; 
			while (c--) {
				int index; cin >> index;
				classes[i] |= 1 << index;
			}
		}		
		cout << (isPossible(0,0)!=INF ? to_string(isPossible(0,0)) : "IMPOSSIBLE") << '\n';		
	}
	return 0;
}