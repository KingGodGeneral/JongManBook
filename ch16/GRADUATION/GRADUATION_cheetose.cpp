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

실행시간 : 8ms

cnt함수 : N에 들어있는 비트(1)의 개수 ex) cnt(1101(2))==3, cnt(100000(2))==1

우선 선수과목과 그 학기에 들을 수 있는 과목 정보를 입력받는다.

그 다음부터는 흔한 DP문제로 바뀐다.

N이 현재 학기, K가 N-1학기까지 들었던 과목들의 집합(을 비트로 표현한 것)을 의미한다.

rr은 N번째 학기에서 열리는 과목 중 여태까지 듣지 않았던 과목들의 집합.

0부터 n-1까지 순회하면서 선수과목 안들은게 있다면 그것도 지움.

남은 최종 후보를 가지고 모든 집합 순회하는데, 그 중 집합의 크기가 l보다 크면 continue, 아니면 그 과목들은 듣는 거로 하고 다음 학기 진행

이 과정중 최소값을 찾으면 되는데, 최종 반환값이 INF이상이면 k개 이상의 과목을 듣지 못한다는 것이므로 "IMPOSSIBLE"을 출력한다.

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
