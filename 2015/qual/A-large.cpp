#include <cstdio>
using namespace std;

#define D(x) 

const int MAX_N = (int)(1e3) + 10;

char st[MAX_N];
int n;

int work()
{
	int sum = 0;
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (st[i] == '0')
			continue;
		if (sum < i)
		{
			ret += i - sum;
			sum = i;
		}
		sum += st[i] - '0';
		D(printf("%d %d\n", i, sum));
	}
	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		n++;
		scanf("%s", st);
		printf("Case #%d: %d\n", i + 1, work());
	}
	return 0;
}
