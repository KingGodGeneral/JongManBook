#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	int n; cin >> n;
	while (n--) {
		string st; cin >> st;
		bool right = true;
		stack<char> brackets;
		char ar[700];
		ar['('] = ')';
		ar['{'] = '}';
		ar['['] = ']';
		ar[')'] = '(';
		ar['}'] = '{';
		ar[']'] = '[';
		for (int i = 0; i < st.size(); i++) {
			if (st[i] == '(' || st[i] == '{' || st[i] == '[') {
				brackets.push(st[i]);
			}
			else if (brackets.empty()) {
				right = false; break;
			}
			else if (ar[st[i]] != brackets.top()) {
				right = false; break;
			}
			else {
				brackets.pop();
			}
		}
		if (!brackets.empty()) right = false;
		if (right) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}