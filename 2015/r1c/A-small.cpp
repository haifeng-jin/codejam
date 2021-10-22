#include <cstdio>
using namespace std;

int r, c, w;

int main()
{
	int t;
	scanf("%d", &t);
	int case_num = 0;
	while (t--)
	{
		case_num++;
		printf("Case #%d: ", case_num);
		scanf("%d%d%d", &r, &c, &w);
		int ans = r * (c / w) + w;
		if (c % w == 0)
			ans--;
		printf("%d\n", ans);
	}
	return 0;
}
