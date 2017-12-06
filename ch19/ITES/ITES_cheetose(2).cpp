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

실행 시간 : 4620ms

종만북 참고해서 unsigned int를 통해 자동으로 MOD 2^32 값을 구하도록 함.

같은 알고리즘인데 큐 내부를 조금 간략하게 만듦

*******************************************************/
inline uint next(uint N)
{
	return N * 214013u + 2531011u;
}
inline uint sig(uint N)
{
	return N % 10000 + 1;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		int n;
		uint k;
		scanf("%u%d", &k, &n);
		uint sum = 0;
		uint now = 1983;
		queue<uint> q;
		int ans = 0;
		fup(TT, 1, n, 1)
		{
			uint PUT = sig(now);
			q.push(PUT);
			sum += PUT;
			while (sum > k)
			{
				sum -= q.front();
				q.pop();
			}
			if (sum == k) ans++;
			now = next(now);
		}
		printf("%d\n", ans);
	}
}