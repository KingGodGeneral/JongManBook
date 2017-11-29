#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int n, k;
int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		list<int> li;
		for (int i = 1; i <= n; ++i) {
			li.push_back(i);
		}

		auto kill = li.begin();
		while (n > 2) {
			kill = li.erase(kill);
			
			if (kill == li.end()) {
				kill = li.begin();
			}
			--n;
			for (int i = 0; i < k - 1; ++i) {
				++kill;
				if (kill == li.end()) kill = li.begin();
			}
		}
		cout << li.front() << " " << li.back() << '\n';		
	}
	return 0;
}