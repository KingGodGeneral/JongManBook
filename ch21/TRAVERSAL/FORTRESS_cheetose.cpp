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

int n;
struct circle {
	int x, y, r;
	bool operator < (const circle& c) { return r < c.r; }
}a[100];
inline bool inside(int i, int j)
{
	if ((a[j].r - a[i].r)*(a[j].r - a[i].r) >(a[i].x - a[j].x)*(a[i].x - a[j].x) + (a[i].y - a[j].y)*(a[i].y - a[j].y)) return 1;
	return 0;
}
Vi v[100];
int dist[100];
int bfs(int S)
{
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(S);
	dist[S] = 0;
	int ans = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++)
		{
			int next = v[x][i];
			if (dist[next] == -1)
			{
				dist[next] = dist[x] + 1;
				q.push(next);
			}
		}
		ans = max(ans, dist[x]);
	}
	return ans;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		for (int i = 0; i < 100; i++) v[i].clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].r);
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (inside(i, j))
				{
					v[i].push_back(j);
					v[j].push_back(i);
					break;
				}
			}
		}
		int t = bfs(0);
		int what;
		for (int i = 0; i<n; i++)
			if (dist[i] == t)
			{
				what = i;
				break;
			}
		printf("%d\n", bfs(what));
	}
}