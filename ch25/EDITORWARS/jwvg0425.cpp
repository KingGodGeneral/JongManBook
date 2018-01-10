#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>

int parent[20001];
bool visit[20001];

int find(int u) 
{
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u == v) return;

	parent[u] = v;

	find(v);
}

void solve()
{
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < 2 * n; i++)
	{
		parent[i] = i;
		visit[i] = false;
	}

	bool cond = false;
	
	for (int i = 0; i < m; i++)
	{
		std::string type;
		int a, b;

		std::cin >> type >> a >> b;

		if (cond)
			continue;

		if (type == "ACK")
		{
			merge(a, b);
			merge(n + a, n + b);
			if (find(a) == find(n + a))
			{
				//모순
				printf("CONTRADICTION AT %d\n", i + 1);
				cond = true;
			}
		}
		else
		{
			merge(a, n + b);
			merge(n + a, b);
			if (find(a) == find(n+a))
			{
				//모순
				printf("CONTRADICTION AT %d\n", i + 1);
				cond = true;
			}
		}
	}

	if (cond)
		return;

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		int g =find(i);
		int ng = find(n + i);

		if (visit[g] || visit[ng])
			continue;

		visit[g] = true;
		visit[ng] = true;

		int c1 = 0, c2 = 0;

		for (int j = 0; j < n; j++)
		{
			if (find(j) == g)
				c1++;
			else if (find(j) == ng)
				c2++;
		}

		count += std::max(c1, c2);
	}

	printf("MAX PARTY SIZE IS %d\n", count);
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		solve();
	}

	return 0;
}
