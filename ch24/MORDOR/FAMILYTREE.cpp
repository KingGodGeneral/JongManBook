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

Vi v[100000];
int parent[100000][18], depth[100000];
int n, q;
void MD()
{
	memset(depth, -1, sizeof(depth));
	queue<int> q;
	q.push(0);
	depth[0] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int next : v[x])
		{
			depth[next] = depth[x] + 1;
			q.push(next);
		}
	}
}
int LCA(int u, int v)
{
	if (depth[u] < depth[v])swap(u, v);
	int dif = depth[u] - depth[v];
	fup(i, 0, 17, 1)
	{
		if (dif&(1 << i))
			u = parent[u][i];
	}
	if (u == v)return u;
	fdn(j, 17, 0, 1)
	{
		while (parent[u][j] != -1 && parent[u][j] != parent[v][j])
			u = parent[u][j], v = parent[v][j];
	}
	return parent[u][0];
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		fup(i, 0, 99999, 1) v[i].clear();
		memset(parent, -1, sizeof(parent));
		scanf("%d%d", &n, &q);
		fup(i, 1, n - 1, 1)
		{
			int x;
			scanf("%d", &x);
			parent[i][0] = x;
			v[x].push_back(i);
		}
		fup(j, 1, 18, 1)
			fup(i, 1, n - 1, 1)
		{
			if (parent[i][j - 1] != -1)
				parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
		MD();
		while (q--)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			int w = LCA(u, v);
			printf("%d\n", depth[u] + depth[v] - 2 * depth[w]);
		}
	}
}