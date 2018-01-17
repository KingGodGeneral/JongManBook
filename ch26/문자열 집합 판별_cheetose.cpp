#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<complex>
#include<cmath>
#include<algorithm>
#include<list>
#include<functional>
#define mp make_pair
#define X first
#define Y second
#define INF 987654321
#define PI 3.14159265358979323846264
#define MOD 1000000007LL
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//µ¿ºÏ³²¼­
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

struct node {
	bool valid;
	int child[26], pi;
	node()
	{
		valid = 0;
		MEM_1(child);
		pi = -1;
	}
};
vector<node> trie;
int init()
{
	node x;
	trie.push_back(x);
	return (int)trie.size() - 1;
}
void add(int n, string &s, int i)
{
	if (i == s.length())
	{
		trie[n].valid = 1;
		return;
	}
	int c = s[i] - 'a';
	if (trie[n].child[c] == -1)
	{
		int next = init();
		trie[n].child[c] = next;
	}
	add(trie[n].child[c], s, i + 1);
}
string s[1000];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	init();
	fup(i, 0, n - 1, 1)
	{
		cin >> s[i];
		add(0, s[i], 0);
	}
	trie[0].pi = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		fup(i, 0, 25, 1)
		{
			int next = trie[x].child[i];
			if (next == -1)continue;
			if (x == 0)trie[next].pi = 0;
			else
			{
				int t = trie[x].pi;
				while (t != 0 && trie[t].child[i] == -1) {
					t = trie[t].pi;
				}
				if (trie[t].child[i] != -1) {
					t = trie[t].child[i];
				}
				trie[next].pi = t;
			}
			int pi = trie[next].pi;
			trie[next].valid |= trie[pi].valid;
			q.push(next);
		}
	}
	int Q;
	cin >> Q;
	while (Q--)
	{
		string ss;
		cin >> ss;
		bool ok = 0;
		int now = 0;
		for (int i = 0; i<ss.length(); i++) {
			int c = ss[i] - 'a';
			while (now != 0 && trie[now].child[c] == -1) {
				now = trie[now].pi;
			}
			if (trie[now].child[c] != -1) {
				now = trie[now].child[c];
			}
			if (trie[now].valid) {
				ok = 1;
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}