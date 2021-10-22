#include <cstdio>
#include <algorithm>
using namespace std;

#define d(x) 

const int MAX_N = 13;

int n;
int f[3];
char out[4] = "RPS";
char ans[1 << MAX_N];

void make(char * a, char * b)
{
	for (int i = 0; a + i != b; i++)
	{
		if (a[i] == b[i])
		{
			continue;
		}
		if (a[i] < b[i])
			return;
		if (a[i] > b[i])
			break;
	}

	for (int i = 0; a + i != b; i++)
	{
		swap(a[i], b[i]);
	}
}

void output(int step, int a, char* s)
{
	if (step == n)
	{
		*s = out[a];
		return;
	}
	output(step + 1, a, s);
	output(step + 1, (a + 2) % 3, s + (1 << (n - step - 1)));
	make(s, s + (1 << (n - step - 1)));
}

bool ok(int a)
{
	int g[3] = {0};
	g[a] = 1;
	for (int i = 0; i < n; i++)
	{
		int h[3] = {0};
		for (int j = 0; j < 3; j++)
		{
			h[j] += g[j];
			h[(j + 2) % 3] += g[j];
		}
		for (int j = 0; j < 3; j++)
			g[j] = h[j];
	}
	d(printf("%d %d %d\n", g[0], g[1], g[2]));
	for (int i = 0; i < 3; i++)
		if (g[i] != f[i])
			return false;
	return true;
}

void work()
{
	for (int i = 0; i < 3; i++)
	{
		if (ok(i))
		{
			output(0, i, ans);
			ans[(1<<n)] = 0;
			puts(ans);
			return;
		}
	}
	puts("IMPOSSIBLE");
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
		scanf("%d%d%d%d", &n, &f[0], &f[1], &f[2]);
		work();
	}
	return 0;
}
