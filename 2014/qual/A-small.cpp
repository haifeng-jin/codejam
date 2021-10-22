#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MAX_CARD_NUM 18

bool possible1[MAX_CARD_NUM];
bool possible2[MAX_CARD_NUM];
int ans;

void set_possible(bool possible[])
{
	int row_num;
	int temp[4];

	scanf("%d", &row_num);
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < 4; j++)
			scanf("%d", &temp[j]);
		if (i != row_num)
			continue;
		for (int j = 0; j < 4; j++)
			possible[temp[j]] = true;
	}
}

int input()
{
	memset(possible1, 0, sizeof(possible1));
	set_possible(possible1);
	memset(possible2, 0, sizeof(possible2));
	set_possible(possible2);

	int true_num = 0;

	for (int i = 1; i <= 16; i++)
		if (possible1[i] && possible2[i])
		{
			true_num++;
			ans = i;
		}
	return true_num;
}

int main()
{
	int case_num;
	scanf("%d", &case_num);
	for (int i = 0; i < case_num; i++)
	{
		printf("Case #%d: ", i + 1);
		int true_num = input();
		if (true_num == 0)
			puts("Volunteer cheated!");
		else if (true_num == 1)
			printf("%d\n", ans);
		else
			puts("Bad magician!");

	}
	return 0;
}
