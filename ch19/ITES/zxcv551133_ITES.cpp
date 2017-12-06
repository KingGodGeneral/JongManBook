#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

struct RNG {
	unsigned seed;
	RNG() : seed(1983) {}
	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u); 
		return ret % 10000 + 1;
	}
};
/*
int optimized(const vector<int>& signals, int k) {
	int ret = 0, tail = 0, rangeSum = signals[0];
	for (int head = 0; head < signals.size(); ++head) {
		while (rangeSum < k && tail + 1 < signals.size()) {
			rangeSum += signals[++tail];
		}
		if (rangeSum == k) ret++;
		rangeSum -= signals[head];
	}
	return ret;
}
*/


int countRanges(int k, int n) {
	RNG rng; //신호 값을 생성하는 난수 생성기
	queue<int> range;
	int ret = 0, rangeSum = 0;
	for (int i = 0; i < n; i++) {
		int newSignal = rng.next();
		rangeSum += newSignal;
		range.push(newSignal);
		//구간 합이 k를 초과하는 동안 구간에서 숫자를 뺀다
		while (rangeSum > k) {
			rangeSum -= range.front();
			range.pop();
		}
		if (rangeSum == k) {
			ret++;
		}		
	}
	return ret;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	int tc; cin >> tc;
	while (tc--) {
		int k, n; cin >> k >> n;
		cout << countRanges(k, n) << '\n';

	}

}