#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

double farm_cost, extra_coin, max_coin;

void input()
{
	scanf("%lf%lf%lf", &farm_cost, &extra_coin, &max_coin);
}

double work()
{
	double start = 0;
	double coin_gain = 2;

	while (true)
	{
		double next_farm_time = start + farm_cost / coin_gain;
		double original_time = start + max_coin / coin_gain;
		double new_time = next_farm_time + max_coin / (coin_gain + extra_coin);
		if (new_time < original_time)
		{
			start = next_farm_time;
			coin_gain += extra_coin;
			continue;
		}
		return original_time;
	}
	return -1;
}

int main()
{
	int case_num;
	
	scanf("%d", &case_num);
	for (int i = 0; i < case_num; i++)
	{
		printf("Case #%d: ", i + 1);
		input();
		printf("%.7f\n", work());
	}
	return 0;
}
