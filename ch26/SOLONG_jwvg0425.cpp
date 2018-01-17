#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>
#include <time.h>
#include <memory>

struct Trie
{
	Trie()
	{
		for (int i = 0; i < 26; i++)
			children[i] = nullptr;
	}

	std::unique_ptr<Trie> children[26];
	bool isLeaf = false;

	std::string highest;
	int maxPriority = -1;

	void Insert(const std::string& str, int priority, int index)
	{
		if (maxPriority < priority || 
			(maxPriority == priority && str < highest))
		{
			maxPriority = priority;
			highest = str;
		}

		if (index == str.size())
		{
			return;
		}

		if (children[str[index] - 'A'] == nullptr)
			children[str[index] - 'A'].reset(new Trie());

		children[str[index] - 'A']->Insert(str, priority, index + 1);
	}

	//return depth
	int find(const std::string& str, int i)
	{
		if (str.size() == i)
			return 0;

		if (i != 0 && highest == str)
		{
			//tab end
			return 1;
		}

		if (children[str[i] - 'A'] != nullptr)
		{
			return 1 + children[str[i] - 'A']->find(str, i + 1);
		}
		
		//no index
		return str.size() - i;
	}
};

void solve()
{
	int n, m;

	Trie root;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		std::string str;
		int p;
		std::cin >> str >> p;
		root.Insert(str, p, 0);
	}

	int count = 0;
	for (int i = 0; i < m; i++)
	{
		std::string str;

		std::cin >> str;

		count += root.find(str, 0);
	}

	std::cout << count + m - 1 << std::endl;
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
