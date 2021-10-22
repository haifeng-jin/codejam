#include <cstdio>
using namespace std;

const int MAX_X = 110;
const int MAX_Y = MAX_X;

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
bool vis[MAX_X][MAX_Y];
int row_num, col_num;
char dir_name[] = "v>^<";
char grid[MAX_X][MAX_Y];
int ans;

void visit(Point a)
{
	vis[a.x][a.y] = true;
}

bool out(Point a)
{
	return a.x < 0 || a.y < 0 || a.x >= row_num || a.y >= col_num;
}

bool visited(Point a)
{
	return vis[a.x][a.y];
}

void input()
{
	scanf("%d%d", &row_num, &col_num);
	for (int i = 0; i < row_num; i++)
	{
		scanf("%s", grid[i]);
	}
}

bool only(Point a)
{
	if (grid[a.x][a.y] == '.')
		return false;
	int ret = 0;
	for (int i = 0; i < row_num; i++)
	{
		if (grid[i][a.y] != '.')
			ret++;
	}
	for (int i = 0; i < col_num; i++)
	{
		if (grid[a.x][i] != '.')
			ret++;
	}
	return ret <= 2;
}

int get_id(char ch)
{
	for (int i = 0; i < 4; i++)
	{
		if (dir_name[i] == ch)
			return i;
	}
	return -1;
}

int cal(Point a)
{
	if (grid[a.x][a.y] == '.')
		return 0;
	int index = get_id(grid[a.x][a.y]);
	Point b = a + dir[index];
	while (!out(b))
	{
		if (grid[b.x][b.y] != '.')
			return 0;
		b = b + dir[index];
	}
	return 1;
}

bool work()
{
	for (int i = 0; i < row_num; i++)
	{
		for (int j = 0; j < col_num; j++)
		{
			if (only(Point(i, j)))
				return false;
		}
	}
	ans = 0;
	for (int i = 0; i < row_num; i++)
	{
		for (int j = 0; j < col_num; j++)
		{
			ans += cal(Point(i, j));
		}
	}
	return true;
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
		if (work())
		{
			printf("%d\n", ans);
		}else
		{
			puts("IMPOSSIBLE");
		}
	}
	return 0;
}
