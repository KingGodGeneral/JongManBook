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
#define INF 1987654321
#define PI 3.14159265358979323846264
#define MOD 1000000007LL
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
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//���ϳ���

/**********************************************************

���� �ð� : 4ms
 
�ʹ� ������ ���� �̿� �˰����̶� ���� ������ �ؾ��ϳ� �ͽ��ϴ�.

�׳� ���� ��ȣ�� �ְ�, ���� ��ȣ�� st.top() Ȯ���ؼ� ������ pop, �ȸ����� NO ����� ����0

�� ������ ���ÿ� ���� ���������� NO ����� ����0

*******************************************************/
int main() {
	int tc;
	scanf("%d", &tc);
A:	while (tc--)
{
	char s[10001];
	stack<char> st;
	scanf("%s", s);
	for (int i = 0; s[i]; i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
		else if (s[i] == ')')
		{
			if (st.empty() || st.top() != '(')
			{
				puts("NO");
				goto A;
			}
			st.pop();
		}
		else if (s[i] == '}')
		{
			if (st.empty() || st.top() != '{')
			{
				puts("NO");
				goto A;
			}
			st.pop();
		}
		else if (s[i] == ']')
		{
			if (st.empty() || st.top() != '[')
			{
				puts("NO");
				goto A;
			}
			st.pop();
		}
	}
	if (!st.empty()) puts("NO");
	else puts("YES");
}
}