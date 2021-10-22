#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 100000

int n;
long long f[maxn];

int cal1(int a)
{
	int g[10];
	int x = 0;
	while (a > 0)
	{
		g[x++] = a % 10;
		a /= 10;
	}
	for (int i = 0; i < x - 1; i++)
		g[x + x - i - 2] = g[i];
	int ret = 0;
	for (int i = 0; i < x * 2 - 1; i++)
		ret = ret * 10 + g[i];
	return ret;
}

int cal2(int a)
{
	int g[10];
	int x = 0;
	while (a > 0)
	{
		g[x++] = a % 10;
		a /= 10;
	}
	for (int i = 0; i < x; i++)
		g[x + x - i - 1] = g[i];
	int ret = 0;
	for (int i = 0; i < x * 2; i++)
		ret = ret * 10 + g[i];
	return ret;
}

bool ok(long long a)
{
	int g[20];
	int x = 0;
	while (a > 0)
	{
		g[x++] = a % 10;
		a /= 10;
	}
	for (int i = 0; i < x / 2; i++)
		if (g[i] != g[x - i - 1])
			return false;
	return true;
}

void init()
{
	n = 0;
	for (int i = 1; i < 1000; i++)
	{
		if (i % 10 == 0)
			continue;
		long long a = cal1(i);
		if (ok(a * a))
			f[n++] = a * a;
		a = cal2(i);
		if (ok(a * a))
			f[n++] = a * a;
	}
	for (int i = 1001; i < 10000; i++)
	{
		if (i % 10 == 0)
			continue;
		long long a = cal1(i);
		if (ok(a * a))
			f[n++] = a * a;
	}
}

int binary_search(int a)
{
	int l = 0;
	int r = n;
	if (f[0] > a)
		return 0;
	if (f[n - 1] < a)
		return n;
	while (l < r)
	{
		int mid = (l + r) / 2 + (l + r) % 2;
		if (f[mid] <= a)
			l = mid;
		else
			r = mid - 1;	
	}
	return l + 1;
}

void work()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = binary_search(b) - binary_search(a - 1);
	printf("%d\n", ans);
}

int main()
{
//	freopen("t.txt", "r", stdin);
//	freopen("y.txt", "w", stdout);
	init();
	sort(f, f + n);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		printf("Case #%d: ", i + 1);
		work();
	}
	return 0;
}
