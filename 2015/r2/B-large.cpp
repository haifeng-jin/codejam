#include <cstdio>
#include <algorithm>
using namespace std;

#define D(x) 

const double eps = 1e-6;
const int MAX_N = 110;

int n;
double aim_v, aim_t;
pair<double, double> elem[MAX_N];	//temperature, rate
double sum_t[MAX_N], sum_r[MAX_N], sum_tr[MAX_N];

void input()
{
	scanf("%d", &n);
	scanf("%lf%lf", &aim_v, &aim_t);
	elem[0].first = elem[0].second = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf%lf", &elem[i].second, &elem[i].first);
	}
}

double cal(double t1, double r1, double t2, double r2)
{
	double diff1 = aim_t - t1;
	double diff2 = t2 - aim_t;
	bool b1 = diff1 < eps && diff1 > -eps;
	bool b2 = diff2 < eps && diff2 > -eps;
	if (b1 && b2)
		return aim_v / (r1 + r2);
	D(printf("%.2f %.2f\n", r1, r2));
	if (b1)
		return aim_v / r1;
	if (b2)
		return aim_v / r2;
	double v1 = aim_v * diff2 / (diff1 + diff2);
	double v2 = aim_v * diff1 / (diff1 + diff2);
	return max(v1 / r1, v2 / r2);
}

int get_left()
{
	for (int i = 1; i < n; i++)
	{
		D(printf("%.8f %.8f %d\n", (sum_tr[n] - sum_tr[i]) / (sum_r[n] - sum_r[i]), aim_t - eps, i));
		if ((sum_tr[n] - sum_tr[i]) / (sum_r[n] - sum_r[i]) > aim_t - eps)
			return i;
	}
	return -1;
}

int get_right()
{
	for (int i = n; i > 1; i--)
	{
		if ((sum_tr[i - 1] / sum_r[i - 1]) < aim_t + eps)
			return i;
	}
	return -1;
}

double work()
{
	sum_t[0] = 0;
	sum_r[0] = 0;
	sum_tr[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		sum_t[i] = sum_t[i - 1] + elem[i].first;
		sum_r[i] = sum_r[i - 1] + elem[i].second;
		sum_tr[i] = sum_tr[i - 1] + elem[i].first * elem[i].second;
	}
	if (aim_t < elem[1].first - eps || aim_t > elem[n].first + eps)
		return -1;
	D(printf("over_all temp = %.4f\n", sum_tr[n] / sum_r[n]));
	if (sum_tr[n] / sum_r[n] < aim_t - eps)
	{
		int a = get_left();
		D(printf("a = %d\n", a));
		return cal(elem[a].first, elem[a].second, (sum_tr[n] - sum_tr[a]) / (sum_r[n] - sum_r[a]), sum_r[n] - sum_r[a]);
	}
	if (sum_tr[n] / sum_r[n] > aim_t + eps)
	{
		int a = get_right();
		return cal(sum_tr[a - 1] / sum_r[a - 1], sum_r[a - 1], elem[a].first, elem[a].second);
	}
	return aim_v / sum_r[n];
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
		sort(elem, elem + n + 1);
		double ans = work();
		if (ans < 0)
			puts("IMPOSSIBLE");
		else
			printf("%.9f\n", ans);
	}
	return 0;
}
