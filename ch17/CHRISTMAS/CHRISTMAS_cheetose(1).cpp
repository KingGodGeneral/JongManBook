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

실행시간 : 260ms

sum[i]함수에 들어가는 값은 sum(a[0]~a[i])%k

모든 sum[i] 의 개수를 카운트 해서 각 개수 별로 nC2 구하면 그게 첫번째 답.

pre[sum[i]]에 현재 i값을 갱신해가면서 O(n) dp로 d[n]에 저장된 게 두번째 답.

이 때 sum[0]=0도 항상 생각해야 한다.

********************************************************************/


int a[100001], sum[100001], pre[100000], d[100001];
ll cnt[100000];
inline ll bi(int n)
{
	return (1LL * n*(n - 1) / 2) % MOD;
}
int n, k;
int main() {
	freopen("input.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		memset(pre, -1, sizeof(pre));
		memset(d, 0, sizeof(d));
		memset(cnt, 0, sizeof(cnt));
		cnt[0]++;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", a + i);
			sum[i] = (sum[i - 1] + a[i]) % k;
			cnt[sum[i]]++;
		}
		ll ans1 = 0;
		for (int i = 0; i < k; i++)
			ans1 = (ans1 + bi(cnt[i])) % MOD;
		printf("%lld ", ans1);
		pre[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			d[i] = d[i - 1];
			if (pre[sum[i]] != -1)d[i] = max(d[i], d[pre[sum[i]]] + 1);
			pre[sum[i]] = i;
		}
		printf("%d\n", d[n]);
	}
}