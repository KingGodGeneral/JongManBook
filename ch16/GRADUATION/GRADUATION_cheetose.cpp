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
#define INF 987654321
#define PI 3.14159265358979323
#define MOD 10007
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

/**********************************************

����ð� : 8ms

cnt�Լ� : N�� ����ִ� ��Ʈ(1)�� ���� ex) cnt(1101(2))==3, cnt(100000(2))==1

�켱 ��������� �� �б⿡ ���� �� �ִ� ���� ������ �Է¹޴´�.

�� �������ʹ� ���� DP������ �ٲ��.

N�� ���� �б�, K�� N-1�б���� ����� ������� ����(�� ��Ʈ�� ǥ���� ��)�� �ǹ��Ѵ�.

rr�� N��° �б⿡�� ������ ���� �� ���±��� ���� �ʾҴ� ������� ����.

0���� n-1���� ��ȸ�ϸ鼭 �������� �ȵ����� �ִٸ� �װ͵� ����.

���� ���� �ĺ��� ������ ��� ���� ��ȸ�ϴµ�, �� �� ������ ũ�Ⱑ l���� ũ�� continue, �ƴϸ� �� ������� ��� �ŷ� �ϰ� ���� �б� ����

�� ������ �ּҰ��� ã���� �Ǵµ�, ���� ��ȯ���� INF�̻��̸� k�� �̻��� ������ ���� ���Ѵٴ� ���̹Ƿ� -1�� ����Ѵ�.

***********************************************/



int pre[12];
int sem[10];
int d[10][1 << 12];
int n, k, m, l;
int cnt(int N)
{
	int c = 0;
	while (N)
	{
		if (N & 1)c++;
		N >>= 1;
	}
	return c;
}
int go(int M, int K)
{
	if (cnt(K) >= k)return 0;
	if (M == m) return INF;
	int &ret = d[M][K];
	if (ret != -1)return ret;
	ret = INF;
	int rr = (sem[M] & ~K);
	for (int i = 0; i < n; i++)
		if ((rr & (1 << i)) && (K&pre[i]) != pre[i]) rr -= (1 << i);
	for (int nk = rr; nk; nk = (nk - 1)&rr)
	{
		if (cnt(nk) > l)continue;
		ret = min(ret, 1 + go(M + 1, K + nk));
	}
	ret = min(ret, go(M + 1, K));
	return ret;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		memset(pre, 0, sizeof(pre));
		memset(sem, 0, sizeof(sem));
		memset(d, -1, sizeof(d));
		scanf("%d%d%d%d", &n, &k, &m, &l);
		for (int i = 0; i < n; i++)
		{
			int N;
			scanf("%d", &N);
			while (N--)
			{
				int x;
				scanf("%d", &x);
				pre[i] |= (1 << x);
			}
		}
		for (int i = 0; i < m; i++)
		{
			int N;
			scanf("%d", &N);
			while (N--)
			{
				int x;
				scanf("%d", &x);
				sem[i] |= (1 << x);
			}
		}
		int t = go(0, 0);
		if (t >= INF)puts("IMPOSSIBLE");
		else printf("%d\n", t);
	}
}