#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//N: 전공과목의 수, K: 들어야할 과목의 수, M: 학기의 수, L: 한학기에 최대로 들을 수 있는 과목의 수
int N, K, M, L;
vector<int> prerequisite;		//특정 과목에 요구되는 선수과목들
vector<int> classes;			//특정 학기에 개설된 과목들
vector<vector<int>> memo;		//이전학기까지 이렇게 선택했을 때 필요한 학기 수
const int INF = 9999999;

int bitCount(int n) {
	if (n == 0) return 0;
	return bitCount(n / 2) + n % 2;
}
//
int isPossible(int semester, int taken) {
	//K개이상을 다 들은 경우
	if (bitCount(taken) >= K) return 0;
	//기저 사례: M학기가 전부 지난 경우
	if (semester == M) return INF;
	//메모이제이션
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
	//이번학기에 아무것도 듣지않은 경우
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