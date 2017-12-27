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
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//µ¿ºÏ³²¼­

int a[50000], b[50000];
int tree[131072];
void init(int node, int S, int E)
{
	if (S == E)
	{
		tree[node] = 1;
		return;
	}
	init(node * 2, S, (S + E) / 2);
	init(node * 2 + 1, (S + E) / 2 + 1, E);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void update(int node, int S, int E, int i)
{
	tree[node]--;
	if (S == E)return;
	if (i <= (S + E) / 2)update(node * 2, S, (S + E) / 2, i);
	else update(node * 2 + 1, (S + E) / 2 + 1, E, i);
}
int find(int node, int S, int E, int k)
{
	if (S == E)return S;
	if (tree[node * 2] >= k)return find(node * 2, S, (S + E) / 2, k);
	return find(node * 2 + 1, (S + E) / 2 + 1, E, k - tree[node * 2]);
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		memset(tree, 0, sizeof(tree));
		int n;
		scanf("%d", &n);
		init(1, 1, n);
		fup(i, 0, n - 1, 1)
			scanf("%d", a + i);
		fdn(i, n - 1, 0, 1)
		{
			int t = find(1, 1, n, i + 1 - a[i]);
			b[i] = t;
			update(1, 1, n, t);
		}
		fup(i, 0, n - 1, 1)
			printf("%d ", b[i]);
		puts("");
	}
}