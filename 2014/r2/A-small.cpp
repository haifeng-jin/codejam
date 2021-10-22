#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 10005
#define D(x) 

int n;
int capacity;
int file[MAX_N];

void input()
{
	scanf("%d", &n);
	scanf("%d", &capacity);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &file[i]);
	}
}

int work()
{
	int l = 0;
	int r = n - 1;
	int ret = 0;
	while (l < r)
	{
		D(printf("%d**%d\n", l, r);)
		if (file[l] + file[r] <= capacity)
		{
			l++;
		}
		r--;
		ret++;
	}
	D(printf("#%d*%d*%d\n", ret, l, r);)

	if (l == r)
		return ret + 1;
	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		input();
		sort(file, file + n);
		printf("Case #%d: %d\n", i + 1, work());
	}
	return 0;
}
