#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

long long m, r;

bool ok(long long n)
{
	long long a = n;
	long long b = 2 * n + 2 * r - 1;
	long long ans = 0;
	while (b)
	{
		if (b & 1)
			ans += a;
		if (ans > m)
			return false;
		a *= 2;
		b >>= 1;
	}
	return true; 
}

void work()
{
	long long l = 1;
	long long r = m;
	while (l < r)
	{
		long long mid = (l + r) / 2 + ((l + r) & 1);
		if (!ok(mid))
			r = mid - 1;
		else
			l = mid;
	}
	printf("%lld\n", l);
}

int main()
{
//	freopen("t.txt", "r", stdin);
//	freopen("y.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		printf("Case #%d: ", i + 1);
		scanf("%lld%lld", &r, &m);
		work();
	}
	return 0;
}
