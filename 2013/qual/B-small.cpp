#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 105

int n, m;
int grid[maxn][maxn];
int row[maxn], col[maxn];

void input()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &grid[i][j]);
}

bool work()
{
	memset(row, -1, sizeof(row));
	memset(col, -1, sizeof(row));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			row[i] = max(grid[i][j], row[i]);
			col[j] = max(grid[i][j], col[j]);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!(grid[i][j] >= row[i] || grid[i][j] >= col[j]))
				return false;
	return true;
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
		input();
		if (work())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
