#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

#define d(x) x

const int MAX_M = 1050;
const int MOD = 1000002013;

struct Elem
{
	int o, e, p;
}elem[MAX_M];

long long expected_income;
int discrete[MAX_M * 4];
int discrete_num;
int n, m;

int get_index(int a)
{
	return lower_bound(discrete, discrete + discrete_num, a) - discrete;
}

void discretization()
{
	sort(discrete, discrete + discrete_num);
	discrete_num = unique(discrete, discrete + discrete_num) - discrete;
}

long long get_money(int num)
{
	long long ret = n;
       	ret += n - num + 1;
	ret *= num;
	ret /= 2;
	ret %= MOD;
	return ret;
}

void input()
{
	scanf("%d%d", &n, &m);
	expected_income = 0;
	discrete_num = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		elem[i].o = a;
		elem[i].e = b;
		elem[i].p = c;
		long long temp = get_money(b - a);
		temp *= c;
		temp %= MOD;
		expected_income += temp;
		expected_income %= MOD;
		discrete[discrete_num++] = a;
		discrete[discrete_num++] = b;
	}
}

long long station[MAX_M * 4];

void make_station()
{
	memset(station, 0, sizeof(station));
	for (int i = 0; i < m; i++)
	{
		station[get_index(elem[i].o)] += elem[i].p;
		station[get_index(elem[i].e)] -= elem[i].p;
	}
}

long long minimum_income;
stack<pair<int, long long> > passenger;

void get_off(int pos, long long num)
{
	while (num > 0)
	{
		long long nearest_people = passenger.top().second;
		long long delta = min(nearest_people, num);
		num -= delta;
		passenger.top().second -= delta;
		long long temp = get_money(pos - passenger.top().first);
		delta %= MOD;
		temp *= delta;
		temp %= MOD;
		minimum_income += temp;
		minimum_income %= MOD;
		if (passenger.top().second == 0)
			passenger.pop();
	}
}

void work()
{
	while (!passenger.empty())
		passenger.pop();
	minimum_income = 0;
	for (int i = 0; i < discrete_num; i++)
	{
		if (station[i] == 0)
			continue;
		if (station[i] > 0)
		{
			passenger.push(make_pair(discrete[i], station[i]));
			continue;
		}
		get_off(discrete[i], -station[i]);
	}
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
		discretization();
		make_station();
		work();
		long long ans = expected_income - minimum_income;
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
