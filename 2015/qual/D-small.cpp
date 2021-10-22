#include <cstdio>
using namespace std;

bool ok(int x, int r, int c)
{
	if (r * c % x != 0)
		return false;
	if (x <= 2)
	{
		return r * c % x == 0;
	}
	if (x == 3)
	{
		return r * c >= 6;
	}
	return r * c >= 12;
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
		int x, r, c;
		scanf("%d %d %d", &x, &r, &c);
		if (ok(x, r, c))
			puts("GABRIEL");
		else
			puts("RICHARD");
	}
	return 0;
}
