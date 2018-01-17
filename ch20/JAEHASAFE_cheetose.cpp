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
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

char s[101][10001];
char ss[101][20001];
int pi[101][10000];
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		MEM0(pi);
		int n;
		scanf("%d", &n);
		scanf("%s", s[0]);
		int N = strlen(s[0]);
		memcpy(ss[0], s[0], N);
		memcpy(ss[0] + N, s[0], N);
		fup(i, 1, n, 1)
		{
			scanf("%s", s[i]);
			memcpy(ss[i], s[i], N);
			memcpy(ss[i] + N, s[i], N);
		}
		fup(k, 0, n, 1)
		{
			for (int i = 1, j = 0; i < N; i++)
			{
				while (j > 0 && s[k][i] != s[k][j]) j = pi[k][j - 1];
				if (s[k][i] == s[k][j]) pi[k][i] = ++j;
			}
		}
		int ans = 0;
		fup(k, 1, n, 1)
		{
			Vi v;
			for (int i = 0, j = 0; i < 2 * N; i++)
			{
				while (j > 0 && ss[k - 1][i] != s[k][j]) j = pi[k][j - 1];
				if (ss[k - 1][i] == s[k][j])
				{
					if (j == N - 1)
					{
						v.push_back(i - N + 1);
						j = pi[k][j];
					}
					else j++;
				}
			}
			if (k & 1)ans += N - v.back();
			else ans += *v.begin();
		}
		printf("%d\n", ans);
	}
}