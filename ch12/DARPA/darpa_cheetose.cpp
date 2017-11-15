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
#define PI 3.14159265358979323
#define MOD 1000000007
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef pair<int, char> P;
int n, m;
double a[200];
bool ok(double k)
{
	//1���� n-1���� ��ĵ�ϸ鼭 cur���� a[i]�� ���̰� k���� ũ�ų� ������ cur���� �����ϰ� c���� 1����
	//�ʱⰪ�� c=1�� ������ a[0]���� ������ ��ġ�ؾ� �ִ� ������ �Ǳ� ����
	int c = 1;
	double cur = a[0];
	fup(i, 1, n - 1, 1)
	{
		if (a[i] - cur >= k)
		{
			cur = a[i];
			c++;
		}
	}
	//�� ī�޶� ������ �ּҰŸ��� k�� �� �� m�� �̻��� ī�޶� ��ġ �� �� �ִ°�?
	return c >= m;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d%d", &m, &n);
		fup(i, 0, n - 1, 1) scanf("%lf", a + i);
		double l = 0, r = 240;
		//�Ҽ��� 3�ڸ������� ������ �ʿ��ϹǷ� r�� l�� ���̰� 1e-4���� Ŭ ���� ����
		while (r - l > 0.0001)
		{
			double M = (l + r) / 2;
			//� M�� ���� �����ϸ� ���� �� Ű���� �ǰ�, �������� ������ ���� �ٿ��� ��.
			if (ok(M)) l = M;
			else r = M;
		}
		//���� ����� r�� ����Ǿ�����
		printf("%.2f\n", r);
	}
}
//freopen("input.txt", "r", stdin);