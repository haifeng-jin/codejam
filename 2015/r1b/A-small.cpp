#include <cstdio>
#include <algorithm>
using namespace std;

#define D(x) x

long long n;
long long basic[20];
long long f[(int)(1e8) + 10];

int get_len(long long a)
{
	int ret = 0;
	while (a > 0)
	{
		a /= 10;
		ret++;
	}
	return ret;
}

long long pow(int a)
{
	long long ret = 1;
	for (int i = 0; i < a; i++)
		ret *= 10;
	return ret;
}

long long reverse(long long a)
{
	long long ret = 0;
	while (a > 0)
	{
		ret = ret * 10 + a % 10;
		a /= 10;
	}
	return ret;
}

long long cal(long long a, int len)
{
	if (len == 1)
		return a - 1;
	if (reverse(a) % pow(len / 2) == 1)
		return a % pow(len - len / 2);
	return reverse(a) % pow(len / 2) + 1 + a % pow(len - len / 2) - 1;
}

long long work()
{
	int len = get_len(n);
	long long ret = basic[len];
	if (reverse(n) == 1)
		return ret;
	
	if (n % pow(len - len / 2) == 0)
	{
		return ret + cal(n - 1, get_len(n - 1)) + 1;
	}
	return ret + cal(n, len);
}

int main()
{
	basic[1] = 1;
	basic[2] = 10;
	for (int i = 3; i <= 15; i++)
	{
		basic[i] = cal(pow(i - 1) - 1, i - 1) + basic[i - 1] + 1;
	}
	int t;
	scanf("%d", &t);
	int case_num = 0;
	while (t--)
	{
		case_num++;
		printf("Case #%d: ", case_num);
		scanf("%lld", &n);
		printf("%lld\n", work());
	}
//	for (int i = 0; i <= pow(8); i++)
//	{
//		f[i] = 20000000000000LL;
//	}
//	f[0] = 0;
//	for (int i = 0; i <= pow(8); i++)
//	{
//		f[i + 1] = min(f[i + 1], f[i] + 1);
//		f[reverse(i)] = min(f[reverse(i)], f[i] + 1);
//	}
//	for (int i = 1; i <= pow(8); i++)
//	{
//		n = i;
//		if (f[n] != work())
//			printf("%lld %lld %lld\n", n, f[n], work());
//	}
	return 0;
}
