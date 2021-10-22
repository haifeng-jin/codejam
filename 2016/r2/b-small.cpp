#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 210;

int n;
int m;
double p[MAX_N];
double selected[MAX_N];
double ans;

void input()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &p[i]);
	}
}

double work()
{
	double ret = 0;
	for (int i = 0; i < (1 << m); i++)
	{
		double temp = 1;
		int cnt = 0;
		for (int j = 0; j < m; j++)
		{
			if ((i >> j) & 1)
			{
				cnt++;
				temp *= selected[j];
			}else
			{
				temp *= 1 - selected[j];
			}
		}
		if (cnt == m / 2)
			ret += temp;
	}
	return ret;
}

void dfs(int s, int num)
{
	if (num == 0)
	{
		ans = max(ans, work());
		return;
	}
	for (int i = s; i < n - num + 1; i++)
	{
		selected[m - num] = p[i];
		dfs(i + 1, num - 1);
	}	
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
		ans = 0;
		dfs(0, m);
		printf("%.9f\n", ans);
	}
	return 0;
}
