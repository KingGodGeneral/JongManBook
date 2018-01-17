#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#define MOD 10007

int unique = 0;

struct Trie
{
	Trie()
	{
		for (int i = 0; i < 26; i++)
			children[i] = nullptr;
	}

	std::unique_ptr<Trie> children[26];
	Trie* fail = nullptr;

	bool isLeaf = false;
	int index = 0;

	void insert(const std::string& str, int index)
	{
		if (index == str.size())
		{
			isLeaf = true;
			return;
		}

		if (children[str[index] - 'a'] == nullptr)
		{
			children[str[index] - 'a'].reset(new Trie());
			children[str[index] - 'a']->index = unique + 1;
			unique++;
		}

		children[str[index] - 'a']->insert(str, index + 1);
	}
};

int table[1001][101];

int calc(Trie* now, int n)
{
	int& res = table[now->index][n];

	if (res != -1)
		return res;

	if (n == 0)
		return 1;

	res = 0;

	for (int i = 0; i < 26; i++)
	{
		Trie* next = now;
		while (next != next->fail && next->children[i] == nullptr)
			next = next->fail;

		if (next->children[i] != nullptr)
			next = next->children[i].get();

		if (next->isLeaf)
			continue;

		res = (res + calc(next, n - 1)) % MOD;
	}

	return res;
}

void solve()
{
	memset(table, -1, sizeof(table));
	unique = 0;
	int n, m;
	std::unique_ptr<Trie> trie(new Trie());

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		std::string pattern;

		std::cin >> pattern;

		trie->insert(pattern, 0);
	}

	std::queue<Trie*> q;

	trie->isLeaf = false;
	trie->fail = trie.get();

	q.push(trie.get());

	while (!q.empty())
	{
		Trie* current = q.front();
		q.pop();

		for (int i = 0; i < 26; i++)
		{
			Trie* next = current->children[i].get();
			if (next == nullptr)
				continue;

			if (current == trie.get())
				next->fail = trie.get();
			else
			{
				auto dest = current->fail;

				while (dest != trie.get() && dest->children[i] == nullptr)
				{
					dest = dest->fail;
				}

				if (dest->children[i] != nullptr)
					dest = dest->children[i].get();
				next->fail = dest;
			}

			if (next->fail->isLeaf)
				next->isLeaf = true;

			q.push(next);
		}
	}

	printf("%d\n", calc(trie.get(), n));
}

int main()
{
	int c;
	scanf("%d", &c);

	for (int i = 0; i < c; i++)
	{
		solve();
	}
	return 0;
}
