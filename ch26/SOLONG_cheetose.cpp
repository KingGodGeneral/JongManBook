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

map<string, int> M;
pair<string, int> p[10000];
struct node {
	bool valid;
	int child[26], word;
	node()
	{
		valid = 0;
		MEM_1(child);
		word = -1;
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
	int c = s[i] - 'A';
	if (trie[n].child[c] == -1)
	{
		int next = init();
		trie[n].child[c] = next;
	}
	add(trie[n].child[c], s, i + 1);
}
void make(int n, string &s, int i)
{
	if (i>0 && trie[n].word == -1)
	{
		trie[n].word = M[s];
	}
	if (i == s.length())return;
	int c = s[i] - 'A';
	make(trie[n].child[c], s, i + 1);
}
int search(int n, string &s, int i)
{
	if (i == s.length())return i;
	if (trie[n].word == M[s])
	{
		return i + 1;
	}
	int c = s[i] - 'A';
	return search(trie[n].child[c], s, i + 1);
}
bool cmp(pair<string, int> p1, pair<string, int> p2)
{
	if (p1.Y != p2.Y)return p1.Y > p2.Y;
	return p1.X < p2.X;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--)
	{
		M.clear();
		trie.clear();
		int n, m;
		cin >> n >> m;
		int ans = m - 1;
		fup(i, 0, n - 1, 1)
			cin >> p[i].X >> p[i].Y;
		sort(p, p + n, cmp);
		fup(i, 0, n - 1, 1)
			M[p[i].X] = i;
		init();
		fup(i, 0, n - 1, 1)
			add(0, p[i].X, 0);
		fup(i, 0, n - 1, 1)
			make(0, p[i].X, 0);
		while (m--)
		{
			string ss;
			cin >> ss;
			if (M.find(ss) == M.end())ans += ss.length();
			else ans += search(0, ss, 0);
		}
		cout << ans << '\n';
	}
}