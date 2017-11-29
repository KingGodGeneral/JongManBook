#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>

std::vector<int> psum;
int N, K;

void one()
{
	std::vector<long long int> sameRemains;

	sameRemains.resize(K, 0);

	for (auto p : psum)
	{
		sameRemains[p]++;
	}
	long long int count = 0;
	const long long int MOD = 20091101;

	for (auto r : sameRemains)
	{
		if (r < 2)
			continue;

		long long int num = r * (r - 1) / 2ll;
		count = (count + num) % MOD;
	}

	printf("%lld ", count);
}

void two()
{
	std::vector<int> prev;
	std::vector<int> res;

	prev.resize(K, -1);

	for (int i = 0; i < psum.size(); i++)
	{
		int ret = 0;
		int p = psum[i];

		if (i > 0)
		{
			//선택 안 하는 경우
			ret = res[i - 1];
		}

		if (prev[p] != -1)
		{
			ret = std::max(ret, 1 + res[prev[p]]);
		}

		prev[p] = i;

		res.push_back(ret);
	}

	printf("%d\n", res.back());

}

void solve()
{
	psum.clear();
	psum.push_back(0);

	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
	{
		int Di = 0;

		scanf("%d", &Di);

		psum.push_back((psum.back() + Di) % K);
	}

	one();
	two();
}

int main()
{
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		solve();
	}

	return 0;
}
