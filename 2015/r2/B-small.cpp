#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define zero(x) (((x)>0?(x):-(x))<eps)
#define eps 1.0E-8

int double_cmp(double a)
{
	if (zero(a))
		return 0;
	return a > 0 ? 1 : -1;
}

int n;
double aim_v, aim_t;
double rate[3];
double temper[3];

bool ok()
{
	if (n == 1)
	{
		return double_cmp(temper[0] - aim_t) == 0;
	}
	return double_cmp(temper[0] - aim_t) * double_cmp(temper[1] - aim_t) <= 0;
}

double work()
{
	if (n == 1)
	{
		return aim_v / rate[0];
	}
	if (double_cmp(aim_t - temper[0]) == 0 && double_cmp(aim_t - temper[1]) == 0)
		return aim_v / (rate[0] + rate[1]);
	if (double_cmp(aim_t - temper[0]) == 0)
		return aim_v / rate[0];
	if (double_cmp(aim_t - temper[1]) == 0)
		return aim_v / rate[1];
	double diff0 = abs(temper[0] - aim_t);
	double diff1 = abs(temper[1] - aim_t);
	double a = aim_v * diff1 / (diff0 + diff1);
	double b = aim_v * diff0 / (diff0 + diff1);
	return max(a / rate[0], b / rate[1]);
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
		scanf("%lf%lf", &aim_v, &aim_t);
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf", &rate[i], &temper[i]);
		}
		if (!ok())
		{
			puts("IMPOSSIBLE");
			continue;
		}
		printf("%.9f\n", work());
	}
	return 0;
}
