#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long p;

long long work(int n, long long p)
{
	if (p == 0)
		return -1;
	long long ret = 2;
	if (p == 1)
		return 0;
	p--;
	long long temp = (1LL << (n - 1));
	while (temp & p)
	{
		ret <<= 1;
		temp >>= 1;
	}
	return min(ret - 2, (1LL << n) - 1);
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
		scanf("%d%lld", &n, &p);
		long long ans = work(n, p);
		long long ans2 = (1LL << n) - (work(n, (1LL << n) - p) + 1) - 1;
		printf("%lld %lld\n", ans, ans2);
	}
	return 0;
}
