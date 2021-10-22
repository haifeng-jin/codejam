#include <cstdio>
#include <algorithm>
using namespace std;

#define D(x) 

int col_num, row_num, n;
int xor_value;

int occupied(int x, int y)
{
	return ((x + y) % 2) ^ xor_value;
}

int cal(int n, int a)
{
	xor_value = a;
	int ret = 0;

	int corner_num = 0;
	corner_num += occupied(1, 1) + occupied(row_num, 1);
	corner_num += occupied(1, col_num) + occupied(row_num, col_num);
	D(printf("corner %d\n", corner_num));
	if (n <= corner_num)
	{
		return n * 2;
	}
	n -= corner_num;
	ret += corner_num * 2;

	int border_num = 0;
	for (int i = 1; i <= col_num; i++)
		border_num += occupied(1, i) + occupied(row_num, i);
	for (int i = 1; i <= row_num; i++)
		border_num += occupied(i, 1) + occupied(i, col_num);
	border_num -= 2 * corner_num;
	D(printf("border %d\n", border_num));
	if (n <= border_num)
	{
		return ret + n * 3;
	}
	n -= border_num;
	ret += border_num * 3;
	ret += n * 4;
	
	return ret;
}

int work()
{
	int ret = 0;
	if (n <= (row_num * col_num + 1) / 2)
	{
		return 0;
	}
	if ((((row_num - 2) * (col_num - 2) + 1) / 2) >= row_num * col_num - n)
	{
		return row_num * col_num * 2 - row_num - col_num - (row_num * col_num - n) * 4;
	}
	if (row_num == 1)
	{
		n -= (row_num * col_num + 1) / 2;
		ret += n * 2;
		if (col_num % 2 == 0)
			ret--;
		return ret;
	}

	ret = min(cal(n - (row_num * col_num + 1) / 2, 0), cal(n - (row_num * col_num - 1) / 2, 1));
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
		scanf("%d%d%d", &row_num, &col_num, &n);
		if (row_num > col_num)
			swap(row_num, col_num);
		printf("%d\n", work());
	}
	return 0;
}
