#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_BLOCK_NUM 1005
#define D(x) 

double block1[MAX_BLOCK_NUM];
double block2[MAX_BLOCK_NUM];
int block_num;

void input()
{
	scanf("%d", &block_num);
	D(printf("%d\n", block_num);)
	for (int i = 0; i < block_num; i++)
		scanf("%lf", &block1[i]);
	for (int i = 0; i < block_num; i++)
		scanf("%lf", &block2[i]);
}

int work(double block1[], double block2[])
{
	//block1 win block2
	int ret = 0;
	int temp = 0;

	for (int i = 0; i < block_num; i++)
	{
		while (temp < block_num && block2[i] >= block1[temp])
			temp++;
		if (temp >= block_num)
			break;
		D(printf("\n*%d %d\n", i, temp);)
		D(printf("\n*%f %f\n", block2[i], block1[temp]);)
		temp++;
		ret++;
	}
	return ret;
}

int main()
{
	int case_num;
	scanf("%d", &case_num);
	for (int i = 0; i < case_num; i++)
	{
		printf("Case #%d: ", i + 1);
		input();
		sort(block1, block1 + block_num);
		sort(block2, block2 + block_num);
		printf("%d %d\n", work(block1, block2), block_num - work(block2, block1));
	}
	return 0;
}
