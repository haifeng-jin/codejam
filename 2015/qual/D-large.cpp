#include <cstdio>
#include <algorithm>
using namespace std;

int r, c, x;

bool work()
{
	if (r > c)
		swap(r, c);
	if (r * c % x != 0)
		return false;
	if (x <= 2)
		return true;
	if (x >= 7)
		return false;

	if (x == 3)
		return r >= 2;
	if (x == 4)
		return r >= 3;
	if (x == 6)
		return r >= 4;
	return r >= 3 && r * c != 15;
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
		scanf("%d%d%d", &x, &r, &c);
		if (work())
			puts("GABRIEL");
		else
			puts("RICHARD");
	}
	return 0;
}
