#ifndef ONLINE_JUDGE
#define _CRT_SECURE_NO_WARNINGS
#endif // !ONLINE_JUDGE
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <queue>
#include <functional> //greater less
using namespace std;

const int MOD = 20090711;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	cin.tie(0); ios_base::sync_with_stdio(0);

	int tc; cin >> tc;
	while (tc--) {
		int n, a, b;
		cin >> n >> a >> b;
		vector<long long> ar(n);
		ar[0] = 1983;
		for (int i = 1; i < n; i++) {
			ar[i] = (ar[i - 1] * a + b) % MOD;
		}
		priority_queue<int, vector<int>, less<int>> maxHeap;
		priority_queue<int, vector<int>, greater<int>> minHeap;
		int ret = 0;
		// 반복문 불변식:
		// 최대 힙의 크기는 최소 힙의 크기와 같거나, 하나 더 크다.
		// 최소 힙의 루트는 최대 힙의 루트보다 크거나 작다.
		int sum = ar[0]; maxHeap.push(ar[0]);
		for (int i = 1; i < n; i++) {
			if (maxHeap.size() == minHeap.size()) {
				maxHeap.push(ar[i]);
			}
			else {
				minHeap.push(ar[i]);
			}
			if (maxHeap.top() > minHeap.top()) {
				int t1 = maxHeap.top();
				int t2 = minHeap.top();
				maxHeap.pop();
				minHeap.pop();
				maxHeap.push(t2);
				minHeap.push(t1);
			}
			sum = (sum + maxHeap.top()) % MOD;
		}
		cout << sum << '\n';
	}
	return 0;
}