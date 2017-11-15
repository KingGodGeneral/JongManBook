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
	//1부터 n-1까지 스캔하면서 cur값과 a[i]의 차이가 k보다 크거나 같으면 cur값을 갱신하고 c값을 1증가
	//초기값이 c=1인 이유는 a[0]에는 무조건 설치해야 최대 개수가 되기 때문
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
	//두 카메라 사이의 최소거리를 k로 할 때 m개 이상의 카메라를 설치 할 수 있는가?
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
		//소수점 3자리까지의 정보만 필요하므로 r과 l의 차이가 1e-4보다 클 때만 돌림
		while (r - l > 0.0001)
		{
			double M = (l + r) / 2;
			//어떤 M에 대해 성립하면 값을 더 키워도 되고, 성립하지 않으면 값을 줄여야 함.
			if (ok(M)) l = M;
			else r = M;
		}
		//최종 결과는 r에 저장되어있음
		printf("%.2f\n", r);
	}
}
//freopen("input.txt", "r", stdin);