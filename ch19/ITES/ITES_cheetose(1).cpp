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
#define INF 1987654321
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
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//동북남서

/**********************************************************

실행 시간 : 5368ms

신호 생성은 next함수와 sig함수를 통해서 생성

각 신호를 계속 큐에 넣다가 지정 값보다 커지면 pop, 같으면 답에 1추가하고 pop

이거 끝날 때까지 반복

*******************************************************/
inline ll next(ll N)
{
	return (N * 214013 + 2531011) % (1LL << 32);
}
inline ll sig(ll N)
{
	return N % 10000 + 1;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		int n;
		ll k;
		scanf("%lld%d", &k, &n);
		ll sum = 0;
		ll now = 1983;
		queue<ll> q;
		int ans = 0;
		fup(TT, 1, n, 1)
		{
			ll PUT = sig(now);
			q.push(PUT);
			sum += PUT;
			if (sum == k)
			{
				ans++;
				sum -= q.front();
				q.pop();
			}
			else if (sum > k)
			{
				while (sum > k)
				{
					sum -= q.front();
					q.pop();
				}
				if (sum == k)
				{
					ans++;
					sum -= q.front();
					q.pop();
				}
			}
			now = next(now);
		}
		printf("%d\n", ans);
	}
}