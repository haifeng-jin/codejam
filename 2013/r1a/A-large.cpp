#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define d(x) 
#define LL long long

long long r, paint;

bool ok(long long a)
{
	long long ret = a;
	ret *= 2;
	ret *= r;
	ret += a * a * 2 - a;
	d(printf("%lld %lld\n", a, ret));
	return ret <= paint;
}

LL binary_search(LL start, LL end)
{
	LL l = start;
	LL r = end;
	while (l < r)
	{
		LL mid = (l + r + 1) / 2;
		if (!ok(mid))
			r = mid - 1;
		else
			l = mid;
	}
	return l;
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
		scanf("%lld %lld", &r, &paint);
		long long ans = binary_search(0, min(paint / 2 / r, 1000000000LL));
		printf("%lld\n", ans);
	}
	return 0;
}
