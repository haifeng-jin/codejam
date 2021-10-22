#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define D(x) 

const int MAX_N = 105;
const int MAX_KEY = 30;

int key_len, word_len, tot_len;
char keyboard[MAX_N], word[MAX_N];
int num[MAX_N];

void input()
{
	scanf("%d%d%d", &key_len, &word_len, &tot_len);
	scanf("%s%s", keyboard, word);
}

bool ok(int a)
{
	for (int i = a; i < word_len; i++)
		if (word[i] != word[i - a])
			return false;
	return true;
}

int get_max_time(int overlap)
{
	for (int i = 0; i < word_len; i++)
		if (num[word[i] - 'A'] == 0)
			return 0;
	if (tot_len < word_len)
		return 0;
	return 1 + (tot_len - word_len) / overlap;
}

void work()
{
	fill_n(num, 26, 0);
	for (int i = 0; i < key_len; i++)
		num[keyboard[i] - 'A']++;

	int max_time = 0;
	int overlap = word_len;
	for (int i = 1; i < word_len; i++)
	{
		if (ok(i))
		{
			overlap = i;
			break;
		}
	}
	max_time = get_max_time(overlap);


	double ans = 1;
	for (int i = 0; i < word_len; i++)
		ans *= num[word[i] - 'A'] * 1.0 / key_len;
	ans *= tot_len - word_len + 1;
	D(printf("%.3f\n", ans));
	D(printf("%d\n", max_time));
	printf("%.8f\n", max_time - ans);
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
		work();
	}
	return 0;
}
