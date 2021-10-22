#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

#define D(x) 

const int MAX_LEN = 200;
const int MAX_N = 105;

int n;
char st[MAX_LEN];
int f[MAX_LEN][MAX_N];
char unified[MAX_N];
int num;
bool ok;

void make(int a)
{
	int cnt = 1;
	int index = 0;
	int len = strlen(st);
	for (int i = 1; i <= len; i++)
	{
		if (st[i] == st[i - 1])
		{
			cnt++;
			continue;
		}
		f[index][a] = cnt;
		index++;
		cnt = 1;
	}
}

int work()
{
	int ret = 0;
	for (int i = 0; i < num; i++)
	{
		sort(f[i], f[i] + n);
		for (int j = 0; j < n; j++)
			ret += abs(f[i][j] - f[i][n / 2]);
	}
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
		scanf("%d", &n);
		ok = true;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", st);
			make(i);
			int temp = unique(st, st + strlen(st)) - st;
			st[temp] = 0;
			if (i == 0)
			{
				num = temp;
				D(printf("st %s\n", st));
				strcpy(unified, st);
				continue;
			}
			D(printf("st %s\n", st));
			if (num != temp || strcmp(unified, st) != 0)
			{
				ok = false;
			}
		}
		if (!ok)
		{
			puts("Fegla Won");
			continue;
		}
		printf("%d\n", work());
	}
	return 0;
}
