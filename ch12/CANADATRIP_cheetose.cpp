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
typedef vector<Pd> VPd; int n;
ll k;
struct vywl {
	int L, M, G;
	vywl() :vywl(0, 0, 0) {}
	vywl(int l, int m, int g) { L = l, M = m, G = g; }
}a[5000];
bool ok(int K)
{
	ll c = 0;
	fup(i, 0, n - 1, 1)
	{
		//K�� L�̻��̸� ��� ǥ������ �� �� �� ����
		if (K >= a[i].L)c += (a[i].M / a[i].G) + 1;
		//K�� L-M���� ������ ǥ������ �� �� ����
		else if (K < a[i].L - a[i].M) continue;
		//�� ���̿� ������ ������ ���
		else
		{
			c += (a[i].M - a[i].L + K) / a[i].G + 1;
		}
	}
	return c >= k;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d%lld", &n, &k);
		fup(i, 0, n - 1, 1)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			a[i] = vywl(x, y, z);
		}
		int l = 0, r = 8030001;
		//�̹��� ������ ���缭 �̺�Ž��
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (ok(m))r = m - 1;
			else l = m + 1;
		}
		printf("%d\n", l);
	}
}
//freopen("input.txt", "r", stdin);