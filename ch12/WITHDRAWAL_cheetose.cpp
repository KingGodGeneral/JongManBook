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
#include<cmath>
#include<algorithm>
#include<list>
#include<functional>
#define X first
#define Y second
#define INF 1000000000
#define MOD 1000000007
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
using namespace std;
const double PI = acos(-1);
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
int n, k;
int r[1000], c[1000];
bool ok(double m)
{
	Vd v;
	//종만북 참고
	fup(i, 0, n - 1, 1)
		v.push_back(m * c[i] - r[i]);
	sort(v.begin(), v.end());
	double cc = 0;
	//그리디하게 v의 원소중 가장 큰 k개의 원소를 더함
	fup(i, n - k, n - 1, 1) cc += v[i];
	//그 값이 양수인가?
	return cc > 0;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d%d", &n, &k);
		fup(i, 0, n - 1, 1)
			scanf("%d%d", &r[i], &c[i]);
		double l = 0, r = 1;
		while (r - l > 0.0000000001)
		{
			double m = (l + r) / 2;
			if (ok(m))r = m;
			else l = m;
		}
		printf("%.8f\n", l);
	}
}
//freopen("input.txt", "r", stdin);