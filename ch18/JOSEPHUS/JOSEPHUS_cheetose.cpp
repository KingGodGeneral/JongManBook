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

실행시간 : 52ms

그냥 큐를 이용해서 조세푸스 설명 그대로 구현한 거라 뭐라 설명해야할 지 모르겠네요.

나중에 세그먼트 트리 공부할 때 더 빠른 다른 방법으로도 설명해드릴게요.

********************************************************************/


int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		queue<int> q;
		fup(i, 1, n, 1) q.push(i);
		int who = 1;
		while (q.size() > 2)
		{
			q.pop();
			fup(i, 1, k - 1, 1)
			{
				int x = q.front();
				q.push(x);
				q.pop();
			}
		}
		int x = q.front();
		q.pop();
		int y = q.front();
		printf("%d %d\n", min(x, y), max(x, y));
	}
}