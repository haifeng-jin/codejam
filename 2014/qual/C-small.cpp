#include <cstdio>
#include <algorithm>
using namespace std;

#define D(x) 

const int MAX_N = 200;

int row_num, col_num, mine_num;
bool swaped;
char grid[MAX_N][MAX_N];

void test()
{
	int cnt = 0;
	for (int i = 0; i < row_num; i++)
	{
		for (int j = 0; j < col_num; j++)
		{
			if (grid[i][j] == '*')
				cnt++;
		}
	}
	if (cnt != mine_num)
	{
		puts("WRONG!!!");
		exit(0);
	}
}

void output()
{
	if (swaped)
	{
		for (int i = 0; i < col_num; i++)
		{
			for (int j = 0; j < row_num; j++)
			{
				putchar(grid[j][i]);
			}
			puts("");
		}
		return;
	}
	for (int i = 0; i < row_num; i++)
	{
		for (int j = 0; j < col_num; j++)
		{
			putchar(grid[i][j]);
		}
		puts("");
	}
}

bool work()
{
	for (int i = 0; i < row_num; i++)
	{
		for (int j = 0; j < col_num; j++)
		{
			grid[i][j] = '*';
		}
	}
	grid[0][0] = 'c';
	int blank = col_num * row_num - mine_num;
	if (blank == 1)
		return true;

	if (row_num == 1)
	{
		grid[0][0] = 'c';
		for (int i = 1; i < col_num - mine_num; i++)
			grid[0][i] = '.';
		return true;
	}

	if (blank == 2 && mine_num != 0)
		return false;

	if (row_num == 2)
	{
		if (mine_num % 2 == 1)
			return false;
		for (int i = 0; i < col_num - mine_num / 2; i++)
			grid[0][i] = grid[1][i] = '.';
		grid[0][0] = 'c';
		return true;
	}

	if (blank < 9 && blank % 2 == 1)
		return false;
	if (mine_num < col_num - 1)
	{
		for (int i = 0; i < row_num; i++)
		{
			for (int j = 0; j < col_num; j++)
			{
				grid[i][j] = '.';
			}
		}
		for (int i = 0; i < mine_num; i++)
		{
			grid[row_num - 1][col_num - i - 1] = '*';
		}
		grid[0][0] = 'c';
		return true;
	}

	int temp = blank / 2 / col_num * 2;
	for (int i = 0; i < temp; i++)
	{
		for (int j = 0; j < col_num; j++)
		{
			grid[i][j] = '.';
		}
	}
	grid[0][0] = 'c';
	int left = blank - temp * col_num;
	if (left == 1)
	{
		grid[temp - 2][col_num - 1] = grid[temp - 1][col_num - 1] = '*';
		for (int i = 0; i < 3; i++)
			grid[temp][i] = '.';
		return true;
	}
	if (left <= 3)
	{
		for (int i = 0; i < left; i++)
			grid[temp][i] = '.';
		return true;
	}

	if (temp > 0 || left % 2 == 0)
	{
		for (int i = 0; i < left / 2; i++)
		{
			grid[temp + 1][i] = '.';
			grid[temp][i] = '.';
		}
		if (left % 2 == 1)
		{
			grid[temp][left / 2] = '.';
		}
		grid[0][0] = 'c';
		return true;
	}

	for (int i = 0; i < (left - 3) / 2; i++)
	{
		grid[1][i] = '.';
		grid[0][i] = '.';
	}
	for (int i = 0; i < 3; i++)
		grid[2][i] = '.';
	grid[0][0] = 'c';
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
		printf("Case #%d:\n", case_num);
		scanf("%d%d%d", &row_num, &col_num, &mine_num);
		if (row_num > col_num)
		{
			swap(row_num, col_num);
			swaped = true;
		}else
		{
			swaped = false;
		}
		if (work())
		{
			D(test());
			output();
		}else
		{
			puts("Impossible");
		}
	}
	return 0;
}
