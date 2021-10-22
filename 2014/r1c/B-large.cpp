#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define D(x) 

const int MAX_LEN = 110;
const int MAX_N = 110;
const int MAX_KEY = 30;
const int MOD = (int)(1e9) + 7;

char st[MAX_LEN];
int middle[MAX_LEN];
bool result;
int start[MAX_KEY];
int end[MAX_KEY];
bool complete[MAX_KEY];
bool exist[MAX_KEY];
int n;

bool all_the_same(char* st)
{
	for (int i = 0; st[i]; i++)
	{
		if (st[i] != st[0])
			return false;
	}
	return true;
}

void make(int a)
{
	if (!result)
		return;
	if (all_the_same(st))
	{
		middle[a] = st[0] - 'a';
		exist[st[0] - 'a'] = true;
		return;
	}
	int len = strlen(st);
	if (end[st[0] - 'a'] != -1)
	{
		result = false;
		return;
	}
	end[st[0] - 'a'] = a;
	exist[st[0] - 'a'] = true;

	if (start[st[len - 1] - 'a'] != -1)
	{
		result = false;
		return;
	}
	start[st[len - 1] - 'a'] = a;
	exist[st[len - 1] - 'a'] = true;

	for (int i = 0; st[i]; i++)
	{
		if (st[i] == st[0] || st[i] == st[len - 1])
			continue;
		complete[st[i] - 'a'] = true;
	}
	bool temp[MAX_KEY];
	memset(temp, 0, sizeof(temp));
	temp[st[0] - 'a'] = true;
	for (int i = 1; st[i]; i++)
	{
		if (temp[st[i] - 'a'] && st[i - 1] != st[i])
		{
			result = false;
			return;
		}
		temp[st[i] - 'a'] = true;
	}
}

struct DSU
{
	int father[MAX_N];

	DSU()
	{}

	DSU(int n)
	{
		for (int i = 0; i < n; i++)
		{
			father[i] = i;
		}
	}

	int find(int a)
	{
		int ret = a;
		while (father[ret] != ret)
			ret = father[ret];
		while (father[a] != a)
		{
			int b = a;
			a = father[a];
			father[b] = ret;
		}
		return ret;
	}

	void merge(int a, int b)
	{
		father[find(a)] = father[find(b)];
	}
}dsu;

long long arrange(int a)
{
	long long ret = 1;
	for (int i = 2; i <= a; i++)
	{
		ret *= i;
		ret %= MOD;
	}
	return ret;
}

int work()
{
	dsu = DSU(n);
	for (int i = 0; i < 26; i++)
	{
		if (start[i] == -1 || end[i] == -1)
			continue;
		if (dsu.find(start[i]) == dsu.find(end[i]))
			return 0;
		dsu.merge(start[i], end[i]);
	}

	for (int i = 0; i < 26; i++)
	{
		int temp = find(middle, middle + n, i) - middle;
		if (temp == n)
		{
			continue;
		}
		if (~start[i])
		{
			dsu.merge(start[i], temp);
		}
		if (~end[i])
		{
			dsu.merge(end[i], temp);
		}
		for (int j = 0; j < n; j++)
		{
			if (middle[j] == i)
			{
				dsu.merge(temp, j);
			}
		}
	}

	long long ret = 1;
	for (int i = 0; i < 26; i++)
	{
		ret *= arrange(count(middle, middle + n, i));
		D(printf("%lld\n", ret));
		ret %= MOD;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (dsu.father[i] == i)
		{
			cnt++;
		}
	}
	ret *= arrange(cnt);
	ret %= MOD;
	return (int)ret;
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

		memset(middle, -1, sizeof(middle));
		memset(start, -1, sizeof(start));
		memset(end, -1, sizeof(end));
		memset(complete, 0, sizeof(complete));
		memset(exist, 0, sizeof(exist));
		result = true;

		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", st);
			make(i);
		}
		for (int i = 0; i < 26; i++)
		{
			if (complete[i] && exist[i])
			{
				result = false;
				break;
			}
		}
		if (!result)
		{
			puts("0");
			continue;
		}
		printf("%d\n", work());
	}
	return 0;
}
