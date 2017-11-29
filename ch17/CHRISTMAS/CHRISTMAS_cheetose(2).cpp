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
#define MOD 20091101
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
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//동북남서


/******************************************************************

실행시간 : 712ms

똑같은 아이디어인데, pre[sum[i]] 대신 upper_bound와 재귀함수를 이용해 구한 것.

********************************************************************/


int a[100001], sum[100001], cnt[100001];
int d[100001];
Vi v[100001];
int n, k;
ll C(int n)
{
	return 1LL * n*(n - 1) / 2;
}
int go(int N)
{
	if (N == n + 1)return 0;
	int &ret = d[N];
	if (ret != -1)return ret;
	ret = go(N + 1);
	Vi::iterator it = upper_bound(ALL(v[sum[N]]), N);
	if (it != v[sum[N]].end())
		ret = max(ret, 1 + go(*it));
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		fup(i, 0, 100000, 1)v[i].clear();
		MEM_1(d);
		MEM0(cnt);
		cnt[0] = 1;
		v[0].push_back(0);
		scanf("%d%d", &n, &k);
		fup(i, 1, n, 1)
		{
			scanf("%d", a + i);
			sum[i] = (sum[i - 1] + a[i]) % k;
			cnt[sum[i]]++;
			v[sum[i]].push_back(i);
		}
		ll ans = 0;
		fup(i, 0, k - 1, 1)
			ans = (ans + C(cnt[i])) % MOD;
		printf("%lld %d\n", ans, go(0));
	}
}