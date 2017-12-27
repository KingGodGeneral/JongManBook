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
#define X first
#define Y second
#define INF 98765432
#define PI 3.14159265358979323
#define MOD 10007
using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
int in[100001], post[100001];
void go(int S, int E, int k)
{
	if (S > E)return;
	if (S == E)
	{
		printf("%d ", post[S]);
		return;
	}
	printf("%d ", post[E]);
	int m = in[post[E]] - k;
	go(S, m - 1, k);
	go(m, E - 1, k + 1);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		in[x] = i;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", post + i);
	go(1, n, 0);
}