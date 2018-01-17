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
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//동북남서
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int pos[4005], sa[4005], lcp[4005], temp[4005], N, d;
string s;
bool cmp(int i, int j)
{
	if (pos[i] != pos[j])return pos[i] < pos[j];
	i += d, j += d;
	return (i < N&&j < N) ? pos[i]<pos[j] : i > j;
}
int k;
bool ok(int K)
{
	int res = 0, t = 0;
	fup(i, 0, N - 2, 1)
	{
		if (lcp[i] >= K)
		{
			t++;
			res = max(res, t);
		}
		else t = 0;
	}
	return res + 1 >= k;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--)
	{
		MEM0(pos);
		MEM0(sa);
		MEM0(lcp);
		MEM0(temp);
		cin >> k >> s;
		N = s.length();
		fup(i, 0, N - 1, 1)
		{
			sa[i] = i;
			pos[i] = s[i];
		}
		for (d = 1;; d *= 2)
		{
			sort(sa, sa + N, cmp);
			fup(i, 1, N - 1, 1)
				temp[i] = temp[i - 1] + cmp(sa[i - 1], sa[i]);
			fup(i, 0, N - 1, 1)
				pos[sa[i]] = temp[i];
			if (temp[N - 1] == N - 1)break;
		}
		for (int i = 0, k = 0; i<N; i++, k = max(k - 1, 0))
		{
			if (pos[i] == N - 1)continue;
			for (int j = sa[pos[i] + 1]; s[i + k] == s[j + k]; k++);
			lcp[pos[i]] = k;
		}
		int l = 1, r = N;
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (ok(m))l = m + 1;
			else r = m - 1;
		}
		cout << r << '\n';
	}
}

