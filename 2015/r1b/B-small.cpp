#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define D(x) 

const int MAX_C = 30;
const int MAX_R = 30;

struct Point
{
	int x, y;
	Point()
	{}
	Point(int x, int y):x(x), y(y)
	{}
	Point operator + (const Point &a)
	{
		return Point(x + a.x, y + a.y);
	}
};

Point dir[4] = {Point(1, 0), Point(0, 1), Point(-1, 0), Point(0, -1)};
int col_num, row_num, n;
bool grid[MAX_R][MAX_C];

bool out(Point a)
{
	return a.x < 0 || a.y < 0 || a.x >= row_num || a.y >= col_num;
}

int cal(int a)
{
	int i = 0;
	int ret = 0;
	int cnt = 0;
	memset(grid, 0, sizeof(grid));
	while (a > 0)
	{
		int x = i / col_num;
		int y = i % col_num;
		grid[x][y] = (a & 1);
		cnt += (a & 1);
		a >>= 1;
		i++;
	}
	if (cnt != n)
		return row_num * col_num * 4;

	D(puts(""));
	for (int i = 0; i < row_num; i++)
	{
		for (int j = 0; j < col_num; j++)
		{
			D(printf("%d", grid[i][j]));
			for (int k = 0; k < 4; k++)
			{
				Point u = Point(i, j);
				Point v = u + dir[k];
				if (out(v))
					continue;
				if (grid[u.x][u.y] && grid[v.x][v.y])
					ret++;
			}
		}
		D(puts(""));
	}
	D(puts(""));
	ret /= 2;
	return ret;
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
		scanf("%d%d%d", &row_num, &col_num, &n);
		D(printf("%d %d %d ", row_num, col_num, n));
		int ans = row_num * col_num * 4;
		for (int i = 0; i < (1 << (row_num * col_num)); i++)
		{
			ans = min(ans, cal(i));
		}
		printf("%d\n", ans);
	}
	return 0;
}
