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
void go(const Vi& a, const Vi& b)
{
	int n = a.size();
	if (n == 0)return;
	if (n == 1)
	{
		printf("%d ", a[0]);
		return;
	}
	int root = a[0];
	int i = 0;
	for (; i < n; i++)
		if (b[i] == root) break;
	Vi a1(a.begin() + 1, a.begin() + i + 1), a2(a.begin() + i + 1, a.end());
	Vi b1(b.begin(), b.begin() + i), b2(b.begin() + i + 1, b.end());
	go(a1, b1);
	go(a2, b2);
	printf("%d ", root);
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		int n;
		scanf("%d", &n);
		Vi a(n), b(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &b[i]);
		go(a, b);
		puts("");
	}
}