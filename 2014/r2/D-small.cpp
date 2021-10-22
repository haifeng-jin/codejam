#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX_STING_NUM 10
#define MAX_LEN 15
#define MAX_TRIE_NUM 5 
#define D(x) 

struct Node
{
	Node* next[26];
}trie[MAX_STING_NUM * MAX_LEN];

char st[MAX_STING_NUM][MAX_LEN];
int trie_num, string_num;
int label[MAX_STING_NUM];
int ans, ans_num;
int node_cnt;
bool vis[MAX_TRIE_NUM];

void input()
{
	scanf("%d%d", &string_num, &trie_num);
	for (int i = 0; i < string_num; i++)
	{
		scanf("%s", st[i]);
	}
}

bool ok()
{
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < string_num; i++)
	{
		vis[label[i]] = true;
	}
	for (int i = 0; i < trie_num; i++)
	{
		if (!vis[i])
		{
			return false;
		}
	}
	return true;
}

int convert(char ch)
{
	return ch - 'A';
}

void add(char *st, Node* node)
{
	if (st[0] == 0)
		return;
	int index = convert(st[0]);
	if (node->next[index] == 0)
	{	
		node->next[index] = trie + node_cnt++;
	}
	add(st + 1, node->next[index]);
}

int cal()
{
	int ret = 0;
	for (int i = 0; i < trie_num; i++)
	{
		node_cnt = 1;
		memset(trie, 0, sizeof(trie));
		for (int j = 0; j < string_num; j++)
		{
			if (label[j] == i)
			add(st[j], trie);
		}
		ret += node_cnt;
	}
	return ret;
}

void dfs(int step)
{
	if (step == string_num)
	{
		if (!ok())
			return;
		int temp_ans = cal();
		if (temp_ans < ans)
		{
			return;
		}
		if (temp_ans == ans)
		{
			ans_num++;
			return;
		}
		ans = temp_ans;
		ans_num = 1;
		D(printf("%d\n", ans);)
		return;
	}
	for (int i = 0; i < trie_num; i++)
	{
		label[step] = i;
		dfs(step + 1);
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		input();
		ans = 0;
		ans_num = 0;
		dfs(0);
		printf("Case #%d: %d %d\n", i + 1, ans, ans_num);
	}
	return 0;
}
