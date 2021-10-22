#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 15
#define D(x) 

int n;
int f[MAX_N];
int g[MAX_N];
bool vis[MAX_N];

void input()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &f[i]);
}

int factorial(int a)
{
	int ret = 1;
	for (int i = 1; i <= a; i++)
	{
		ret *= i;
	}
	return ret;
}

bool ok()
{
	int i = 0;
	while (i + 1 < n && g[i + 1] > g[i])
		i++;
	while (i + 1 < n && g[i + 1] < g[i])
		i++;
	D(printf("#%d,%d\n", i, n -1);)
	return i == n - 1;
}

int cal()
{
	int ret = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		for (int j = 0; j < n; j++)
		{
			if (g[i] == f[j])
			{
				vis[j] = true;
				break;
			}
			if (!vis[j])
			{
				D(printf("%d***%d\n", i, j);)
				temp++;
			}
		}
		ret += temp;
	}
	return ret;
}

int work()
{
	int round_num = factorial(n);
	int ret = n * n;
	memcpy(g, f, n * sizeof(int));
	for (int i = 0; i < round_num; i++)
	{
		if (ok())
		{
			ret = min(ret, cal());
		}
		next_permutation(g, g + n);
	}
	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		input();
		printf("Case #%d: %d\n", i + 1, work());
	}
}
