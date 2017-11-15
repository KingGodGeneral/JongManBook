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
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef pair<int, char> P;
int n;
Pd p[100];
bool a[100][100];
inline double dist(Pd p1, Pd p2)
{
	return sqrt((p1.X - p2.X)*(p1.X - p2.X) + (p1.Y - p2.Y)*(p1.Y - p2.Y));
}
bool ok()
{
	//0�� �������� �ٸ� ��� ������ �� �� ������ true, ������ false ��ȯ
	fup(i, 1, n - 1, 1)
		if (!a[0][i])return 0;
	return 1;
}
bool OK(double k)
{
	//���� ������ �Ÿ��� k���� �� �� �����ϰ� �÷��̵� �ͼ� �˰����� ���ؼ� ������ ���� i���� j���� �� �� �ִ��� Ȯ���ϰ�
	//���� ok() �Լ��� ���ؼ� 0�� �������� ��� ������ �� �� �ִ� �� Ȯ��
	MEM0(a);
	fup(i, 0, n - 1, 1)
		fup(j, i + 1, n - 1, 1)
		if (dist(p[i], p[j]) <= k)a[i][j] = a[j][i] = 1;
	fup(k, 0, n - 1, 1)
		fup(i, 0, n - 1, 1)
		fup(j, 0, n - 1, 1)
		if (a[i][k] && a[k][j]) a[i][j] = 1;
	if (ok())return 1;
	return 0;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d", &n);
		fup(i, 0, n - 1, 1)
			scanf("%lf%lf", &p[i].X, &p[i].Y);
		double l = 0, r = 1500;
		while (r - l > 0.0001)
		{
			double m = (l + r) / 2;
			if (OK(m))r = m;
			else l = m;
		}
		printf("%.2f\n", l);
	}
}
//freopen("input.txt", "r", stdin);