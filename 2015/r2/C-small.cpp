#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define D(x) 

const int MAX_N = 30;
const int MAX_LEN = 21000;
const int MAX_WORD_NUM = 20;
const int MAX_WORD_LEN = 20;

int n;
char sentence[MAX_N][MAX_LEN];
char english[MAX_LEN];
char french[MAX_LEN];
int temp_num[MAX_LEN];

int word[MAX_N][MAX_WORD_NUM];
int word_num[MAX_N];

char dictionary[MAX_LEN][MAX_WORD_LEN];
int dic_cnt;

bool is_en[MAX_LEN], is_fr[MAX_LEN];
bool temp_en[MAX_LEN], temp_fr[MAX_LEN];

int need_check[MAX_N * MAX_WORD_NUM];
int need_cnt;

bool complete[MAX_LEN];

int get_id(char *st)
{
	int i = 0;
	while (i < dic_cnt)
	{
		if (strcmp(dictionary[i], st) == 0)
			return i;
		i++;
	}
	strcpy(dictionary[dic_cnt], st);
	return dic_cnt++;
}

int make(char* sen, int* index)
{
	int temp = 0;
	int len = strlen(sen);
	int i = 0;
	while (temp < len - 1)
	{
		char st[20];
		sscanf(sen + temp, "%s", st);
		index[i++] = get_id(st);
		temp += strlen(st);
		while (sen[temp] == ' ')
			temp++;
	}
	return i;
}

int cal(int bit)
{
	memset(temp_en, 0, sizeof(temp_en));
	memset(temp_fr, 0, sizeof(temp_fr));
	int cnt = 0;
	for (cnt = 0; cnt < n; cnt++)
	{
		int temp = bit & 1;
		bit >>= 1;
		D(printf("temp %d\n", temp));
		if (temp)
		{
			for (int i = 0; i < word_num[cnt]; i++)
			{
				temp_en[word[cnt][i]] = true;
				D(printf("%d %d\n", i, word[cnt][i]));
			}
		}else
		{
			for (int i = 0; i < word_num[cnt]; i++)
			{
				temp_fr[word[cnt][i]] = true;
				D(printf("%d %d\n", i, word[cnt][i]));
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < need_cnt; i++)
	{
		int index = need_check[i];
		D(printf("%d %d\n", temp_fr[index], temp_en[index]));
		if ((is_fr[index] || temp_fr[index]) && (is_en[index] || temp_en[index]))
		{
			ret++;
		}
	}
	return ret;
}

int work()
{
	memset(is_en, 0, sizeof(is_en));
	memset(is_fr, 0, sizeof(is_fr));
	int num = make(english, temp_num);
	for (int i = 0; i < num; i++)
	{
		is_en[temp_num[i]] = true;
	}
	num = make(french, temp_num);
	for (int i = 0; i < num; i++)
	{
		is_fr[temp_num[i]] = true;
	}
	for (int i = 0; i < n; i++)
	{
		word_num[i] = make(sentence[i], word[i]);
	}

	memset(complete, 0, sizeof(complete));
	int basic = 0;
	for (int i = 0; i < dic_cnt; i++)
	{
		if (is_en[i] && is_fr[i])
		{
			basic++;
			complete[i] = true;
		}
	}
	D(printf("basic %d\n", basic));

	need_cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < word_num[i]; j++)
		{
			if (complete[word[i][j]])
				continue;
			need_check[need_cnt++] = word[i][j];
		}
	}

	sort(need_check, need_check + need_cnt);
	need_cnt = unique(need_check, need_check + need_cnt) - need_check;
	D(printf("need_cnt = %d\n", need_cnt));
	int ret = MAX_LEN;
	for (int i = 0; i < (1 << n); i++)
	{
		ret = min(ret, cal(i));
	}
	return ret + basic;
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
		scanf("%d", &n);
		getchar();
		fgets(english, MAX_LEN, stdin);
		fgets(french, MAX_LEN, stdin);
		n -= 2;
		for (int i = 0; i < n; i++)
		{
			fgets(sentence[i], MAX_LEN, stdin);
		}
		dic_cnt = 0;
		printf("%d\n", work());
	}
	return 0;
}
