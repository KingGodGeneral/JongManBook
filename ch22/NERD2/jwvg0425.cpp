#include <stdio.h>
#include <algorithm>
#include <map>

void solve()
{
	int n;
	int sum = 0;
	std::map<int, int> people;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int p, q;

		scanf("%d %d", &p, &q);

		auto right = people.lower_bound(p);

		if (right == people.end() || right->second < q) // 내 p가 제일 크거나 - 내 오른쪽 애의 q가 나보다 작은 경우는 삽입하면 됨
		{
			//왼쪽부터 확인
			if (right != people.begin())
			{
				right--;

				while (true)
				{
					if (right->second > q)
						break;

					if (right == people.begin())
					{
						people.erase(right);
						break;
					}
					else
					{
						auto nextRight = right;
						nextRight--;

						people.erase(right);
						right = nextRight;
					}
				}
			}

			people[p] = q;
		}
		//그 외의 경우는 무시됨

		sum += people.size();
	}

	printf("%d\n", sum);
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
