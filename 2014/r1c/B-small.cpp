#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define D(x) 

int n;
int f[110];
char name[110][110];

bool ok()
{
	char st[11000];
	st[0] = 0;
	for (int i = 0; i < n; i++)
	{
		strcpy(st + strlen(st), name[f[i]]);
	}
	bool temp[30];
	memset(temp, 0, sizeof(temp));
	temp[st[0] - 'a'] = true;
	for (int i = 1; st[i]; i++)
	{
		if (temp[st[i] - 'a'] && st[i - 1] != st[i])
		{
			return false;
		}
		temp[st[i] - 'a'] = true;
	}
	D(puts(st));
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
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", name[i]);
			char* temp = unique(name[i], name[i] + strlen(name[i]));
			*temp = 0;
			f[i] = i;
		}
		int ans = 0;
		do
		{
			if (ok())
				ans++;
		}while (next_permutation(f, f + n));
		printf("%d\n", ans);
	}
	return 0;
}
