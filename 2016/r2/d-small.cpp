#include <algorithm>
#include <cstdio>
using namespace std;

#define d(x) 

const int MAX_N = 5;

int n;
int f[MAX_N][MAX_N];
int ans;

void input()
{
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char ch = getchar();
			if (ch == '1')
				f[i][j] = 1;
			else
				f[i][j] = 0;
		}
		getchar();
	}
}

bool ok()
{
	int worker[MAX_N];
	for (int i = 0; i < n; i++)
	{
		int worker_cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (f[j][i] == 1)
			{
				worker[worker_cnt++] = j;
			}
		}
		d(printf("%d\n", worker_cnt));
		if (worker_cnt == 0)
			return false;

		int machine_cnt = 0;
		for (int j = 0; j < worker_cnt; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (f[worker[j]][k] != f[worker[0]][k])
				{
					return false;
				}
				if (f[worker[j]][k] == 1)
					machine_cnt++;
			}
		}
		if (worker_cnt != machine_cnt / worker_cnt || machine_cnt % worker_cnt != 0)
			return false;

	}
	return true;
}

void dfs(int step, int cnt)
{
	if (step == n * n)
	{
		if (ok())
			ans = min(ans, cnt);
		return;
	}
	int x = step / n;
	int y = step % n;
	d(printf("x y = %d %d\n", x, y));
	if (f[x][y] == 1)
		dfs(step + 1, cnt);
	else
	{
		dfs(step + 1, cnt);
		f[x][y] = 1;
		dfs(step + 1, cnt + 1);
		f[x][y] = 0;
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
		ans = n * n;
		dfs(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
