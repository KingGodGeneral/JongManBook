#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> getPartialMatch(const std::string& needle)
{
	std::vector<int> pi(needle.size(), 0);

	int begin = 1, matched = 0;

	while (begin + matched < needle.size())
	{
		if (needle[begin + matched] == needle[matched])
		{
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else if (matched == 0)
		{
			begin++;
		}
		else
		{
			begin += matched - pi[matched - 1];
			matched = pi[matched - 1];
		}
	}

	return pi;
}

int search(const std::string& haystack, const std::string& needle)
{
	auto pi = getPartialMatch(needle);

	int matched = 0, begin = 0;

	while (true)
	{
		if (matched < needle.size() && haystack[(begin + matched) % haystack.size()] == needle[matched])
		{
			matched++;
			if (matched == needle.size())
				return begin;
		}
		else if (matched == 0)
		{
			begin++;
		}
		else
		{
			begin += matched - pi[matched - 1];
			matched = pi[matched - 1];
		}
	}

	return -1;
}

void solve()
{
	int N;

	std::vector<std::string> states;

	std::cin >> N;

	for (int i = 0; i <= N; i++)
	{
		std::string state;

		std::cin >> state;

		states.emplace_back(state);
	}

	int res = 0;

	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
		{
			res += search(states[i + 1], states[i]);
		}
		else
		{
			res += search(states[i], states[i + 1]);
		}
		
	}

	std::cout << res << std::endl;
}

int main()
{
	std::cout.sync_with_stdio(false);

	int C;
	
	std::cin >> C;

	for (int i = 0; i < C; i++)
	{
		solve();
	}
}
