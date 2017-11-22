#include <stdio.h>
#include <memory.h>
#include <bitset>
#include <algorithm>

int N, K, M, L;
int prev[20] = { 0, };
int classes[20] = { 0, };

int table[10][1 << 13];

int bitCount(int n)
{
	return std::bitset<32>(n).count();
}

int graduate(int semester, int taken)
{
	if (bitCount(taken) >= K) return 0;

	if (semester == M) 
		return 987654321;

	int& ret = table[semester][taken];

	if (ret != -1)
		return ret;

	ret = 987654321;

	int canTake = (classes[semester] & ~taken);

	for (int i = 0; i < N; i++)
	{
		if ((canTake & (1 << i)) &&
			(taken & prev[i]) != prev[i])
		{
			canTake &= ~(1 << i);
		}
	}

	for (int take = canTake; take > 0; take = ((take - 1) & canTake))
	{
		if (bitCount(take) > L) continue;

		ret = std::min(ret, graduate(semester + 1, (taken | take)) + 1);
	}

	ret = std::min(ret, graduate(semester + 1, taken));
	return ret;
}

void solve()
{
	memset(table, -1, sizeof(table));
	memset(prev, 0, sizeof(prev));
	memset(classes, 0, sizeof(classes));

	scanf("%d %d %d %d", &N, &K, &M, &L);

	for (int i = 0; i < N; i++)
	{
		int R;

		scanf("%d", &R);

		for (int j = 0; j < R; j++)
		{
			int Rj;

			scanf("%d", &Rj);

			prev[i] |= (1 << Rj);
		}
	}

	for (int i = 0; i < M; i++)
	{
		int C;

		scanf("%d", &C);

		for (int j = 0; j < C; j++)
		{
			int Cj;

			scanf("%d", &Cj);

			classes[i] |= (1 << Cj);
		}
	}

	int answer = graduate(0, 0);

	if (answer == 987654321)
		printf("IMPOSSIBLE\n");
	else
		printf("%d\n", answer);
}

int main()
{
	int C;

	scanf("%d", &C);

	for (int i = 0; i < C; i++)
	{
		solve();
	}

	return 0;
}
