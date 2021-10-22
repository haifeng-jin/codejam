#include <cstdio>
using namespace std;

long long p, q;

void input()
{
	char st[100];
	scanf("%s", st);
	for (int i = 0; st[i]; i++)
	{
		if (st[i] == '/')
		{
			st[i] = ' ';
			break;
		}
	}
	sscanf(st, "%lld%lld", &p, &q);
}

long long gcd(long long p, long long q)
{
	if (q == 0)
		return p;
	return gcd(q, p % q);
}

int main()
{
	int t;
	scanf("%d", &t);
	int case_num = 0;
	while (t--)
	{
		case_num++;
		printf("Case #%d: ", case_num);
		input();
		long long g = gcd(p, q);
		p /= g;
		q /= g;
		if ((q & (-q)) != q)
		{
			puts("impossible");
			continue;
		}
		while (p > 1)
		{
			p /= 2;
			q /= 2;
		}
		int cnt = 0;
		while (q > 1)
		{
			cnt++;
			q /= 2;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
