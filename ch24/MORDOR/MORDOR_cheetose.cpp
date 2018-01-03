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
#define MOD 1000000007
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

int a[100000], mintree[262144], maxtree[262144];
void init(int node, int S, int E)
{
	if (S == E)
	{
		mintree[node] = a[S];
		maxtree[node] = a[S];
		return;
	}
	init(node * 2, S, (S + E) / 2);
	init(node * 2 + 1, (S + E) / 2 + 1, E);
	mintree[node] = min(mintree[node * 2], mintree[node * 2 + 1]);
	maxtree[node] = max(maxtree[node * 2], maxtree[node * 2 + 1]);
}
int maxfind(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return 0;
	if (i <= S && j >= E)return maxtree[node];
	return max(maxfind(node * 2, S, (S + E) / 2, i, j), maxfind(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
int minfind(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return INF;
	if (i <= S && j >= E)return mintree[node];
	return min(minfind(node * 2, S, (S + E) / 2, i, j), minfind(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		int n, q;
		scanf("%d%d", &n, &q);
		fup(i, 0, n - 1, 1)
			scanf("%d", a + i);
		init(1, 0, n - 1);
		while (q--)
		{
			int i, j;
			scanf("%d%d", &i, &j);
			printf("%d\n", maxfind(1, 0, n - 1, i, j) - minfind(1, 0, n - 1, i, j));
		}
	}
}