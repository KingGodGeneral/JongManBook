#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> getSuffixArray(const std::string& str)
{
	std::vector<int> group(str.size() + 1);
	int t = 1;

	for (int i = 0; i < str.size(); i++) 
		group[i] = str[i];

	group[str.size()] = -1;

	std::vector<int> res(str.size());

	for (int i = 0; i < str.size(); i++)
		res[i] = i;

	while (t < str.size())
	{
		auto compare = [&group, t](int lhs, int rhs)
		{
			if (group[lhs] != group[rhs])
				return group[lhs] < group[rhs];

			return group[lhs + t] < group[rhs + t];
		};

		std::sort(res.begin(), res.end(), compare);

		t *= 2;

		if (t >= str.size())
			break;

		std::vector<int> newGroup(str.size() + 1);
		newGroup.back() = -1;
		newGroup[res[0]] = 0;

		for (int i = 1; i < str.size(); i++)
		{
			if (compare(res[i - 1], res[i]))
				newGroup[res[i]] = newGroup[res[i - 1]] + 1;
			else
				newGroup[res[i]] = newGroup[res[i - 1]];
		}

		group = std::move(newGroup);
	}

	return res;
}

int commonCount(const std::string& str, int a, int b)
{
	int count = 0;

	while (a < str.size() && b < str.size() && str[a] == str[b])
	{
		a++;
		b++;
		count++;
	}

	return count;
}

void solve()
{
	int K;
	std::string str;

	std::cin >> K >> str;

	int count = 0;

	auto suffix = getSuffixArray(str);

	for (int i = 0; i <= str.size() - K; i++)
	{
		int c = commonCount(str, suffix[i], suffix[i + K - 1]);

		if (c > count)
			count = c;
	}

	std::cout << count << std::endl;
}

int main()
{
	int C;

	std::cin >> C;

	for (int i = 0; i < C; i++)
	{
		solve();
	}

	return 0;
}
