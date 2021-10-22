#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define D(x) 

const int INF = 0x3f3f3f3f;
const int MAX_N = (int)(1e4) + 10;

int n;
int f[MAX_N];

int cal(int a)
{
	int ret = a;
	for (int i = 0; i < n; i++)
	{
		int temp = f[i] / a;
		if (f[i] % a != 0)
			temp++;
		ret += temp - 1;
	}
	return ret;
}

int work()
{
	int ret = INF;
	for (int i = 1; i <= 1000; i++)
	{
		ret = min(ret, cal(i));
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
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &f[i]);
		}
		sort(f, f + n);
		printf("Case #%d: %d\n", case_num, work());
	}
	return 0;
}
