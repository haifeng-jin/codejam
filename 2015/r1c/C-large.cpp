#include <cstdio>
using namespace std;

const int MAX_N = 110;

int multi, num, target;
long long f[MAX_N];

int work()
{
	long long cur = 0;
	int temp = 0;
	int ret = 0;
	while (cur < target)
	{
		while (temp < num && f[temp] <= cur + 1)
		{
			cur += multi * f[temp];
			temp++;
		}
		if (cur >= target)
			break;
		cur = (cur + 1) * multi + cur;
		ret++;
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
		scanf("%d%d%d", &multi, &num, &target);
		for (int i = 0; i < num; i++)
		{
			scanf("%lld", &f[i]);
		}
		printf("%d\n", work());
	}
	return 0;
}
