#include <cstdio>
#include <algorithm>
using namespace std;

#define D(x) x

const int MAX_LEN = (int)(1e4) + 10;

long long len, repeat;
char st[MAX_LEN];
int f[20];

int get_num(char ch)
{
	if (ch == 'i')
		return 2;
	if (ch == 'j')
		return 3;
	return 4;
}

int multiply(int a, int b)
{
	int plus = 1;
	if (a < 0)
	{
		a = -a;
		plus = -plus;
	}
	if (b < 0)
	{
		b = -b;
		plus = -plus;
	}
	if (b == 1)
		swap(a, b);
	if (a == 1)
		return plus * b;
	if (a == b)
		return -plus;
	if (a == 2)
	{
		if (b == 3)
			return plus * 4;
		if (b == 4)
			return plus * (-3);
	}
	if (a == 3)
	{
		if (b == 2)
			return plus * (-4);
		if (b == 4)
			return plus * 2;
	}
	if (b == 2)
		return plus * 3;
	return plus * (-2);
}

bool work()
{
	int temp = 1;
	for (int i = 0; i < len; i++)
	{
		temp = multiply(temp, get_num(st[i]));
	}
	int once = temp;
	int cnt = 1;
	f[1] = once;
	while (cnt < repeat)
	{
		temp = multiply(temp, once);
		cnt++;
		f[cnt] = temp;
		if (temp == once)
			break;
	}
	int result;
	if (cnt == repeat)
		result = f[repeat];
	else
		result = f[repeat % (cnt - 1)];
 
	if (result != -1)
		return false;

	int limit = cnt;
	if (repeat < limit)
		limit = repeat;
	temp = 1;
	int left = -1;
	for (int i = 0; i < limit * len; i++)
	{
		temp = multiply(temp, get_num(st[i % len]));
		if (temp == 2)
		{
			left = i;
			break;
		}
	}

	if (left == -1)
		return false;

	temp = 1;
	int right = -1;
	for (int i = limit * len - 1; i >= 0; i--)
	{
		temp = multiply(get_num(st[i % len]), temp);
		if (temp == 4)
		{
			right = limit * len - 1 - i;
			break;
		}
	}

	if (right == -1)
		return false;

	long long ipos = left;
	long long kpos = repeat * len - 1 - right;
	return ipos < kpos - 1;
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
		scanf("%lld%lld", &len, &repeat);
		scanf("%s", st);
		if (work())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
