#include <cstdio>
#include <set>
#include <cstring>
using namespace std;

set<long long> ans;

bool palindrome(long long a)
{
	char st[100];
	sprintf(st, "%lld", a);
	int len = strlen(st);
	for (int i = 0; i < len / 2; i++)
	{
		if (st[i] != st[len - i - 1])
			return false;
	}
	return true;
}

void add(int a)
{
	long long temp = a;
	temp *= a;
	if (palindrome(temp))
		ans.insert(temp);
}

void make(int a)
{
	int temp = a;
	int b = 0;
	int ten = 1;
	while (temp > 0)
	{
		b = b * 10 + temp % 10;
		temp /= 10;
		ten *= 10;
	}
	add(a * ten + b);
	add(a / 10 * ten + b);
}

void work()
{
	ans.clear();
	for (int i = 1; i < 10000; i++)
	{
		make(i);
	}
}

int main()
{
	work();
	int t;
	scanf("%d", &t);
	int case_num = 0;
	while (t--)
	{
		case_num++;
		printf("Case #%d: ", case_num);

		long long a, b;
		scanf("%lld%lld", &a, &b);

		set<long long>::iterator pa = ans.lower_bound(a);
		set<long long>::iterator pb = ans.lower_bound(b + 1);

		int temp = distance(pa, pb);
		printf("%d\n", temp);
	}
	return 0;
}
