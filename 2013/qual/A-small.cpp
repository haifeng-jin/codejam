#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 10

char grid[maxn][maxn];
bool vis[1000];

void input()
{
	for (int i = 0; i < 4; i++)
		scanf("%s", grid[i]);
}

void work()
{
	bool complete = true;
	bool xwon = false;
	bool owon = false;
	for (int i = 0; i < 4; i++)
	{
		vis['X'] = vis['O'] = vis['.'] = vis['T'] = false;
		for (int j = 0; j < 4; j++)
			vis[grid[i][j]] = true;
		if (vis['.'])
		{
			complete = false;
			continue;
		}
		if (vis['X'] && !vis['O'])
			xwon = true;
		if (vis['O'] && !vis['X'])
			owon = true;
	}
	for (int j = 0; j < 4; j++)
	{
		vis['X'] = vis['O'] = vis['.'] = vis['T'] = false;
		for (int i = 0; i < 4; i++)
			vis[grid[i][j]] = true;
		if (vis['.'])
		{
			complete = false;
			continue;
		}
		if (vis['X'] && !vis['O'])
			xwon = true;
		if (vis['O'] && !vis['X'])
			owon = true;
	}
	vis['X'] = vis['O'] = vis['.'] = vis['T'] = false;
	for (int j = 0; j < 4; j++)
		vis[grid[j][j]] = true;
	if (vis['.'])
		complete = false;
	else if (vis['X'] && !vis['O'])
		xwon = true;
	else if (vis['O'] && !vis['X'])
		owon = true;

	vis['X'] = vis['O'] = vis['.'] = vis['T'] = false;
	for (int j = 0; j < 4; j++)
		vis[grid[3 - j][j]] = true;
	if (vis['.'])
		complete = false;
	else if (vis['X'] && !vis['O'])
		xwon = true;
	else if (vis['O'] && !vis['X'])
		owon = true;

	if (xwon)
		puts("X won");
	else if (owon)
		puts("O won");
	else if (complete)
		puts("Draw");
	else
		puts("Game has not completed");
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
		work();
	}
	return 0;
}
