#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX_LEN 50

long long A, B, K;
int a[MAX_LEN], b[MAX_LEN], k[MAX_LEN];
long long memoize[MAX_LEN][2][2][2];

void input()
{
    scanf("%lld%lld%lld", &A, &B, &K);
}

int convert(long long A, int a[])
{
    int i = 0;
    while (A)
    {
        a[i] = A & 1;
        A >>= 1;
        i++;
    }
    return i;
}

long long dfs(int current_bit, bool less_a, bool less_b, bool less_k)
{
    if (current_bit == -1)
    {
        if (less_a && less_b && less_k)
        {
            return 1;
        }
        return 0;
    }
    if (memoize[current_bit][less_a][less_b][less_k] != -1)
        return memoize[current_bit][less_a][less_b][less_k];
    bool one_a = less_a || a[current_bit] == 1;
    bool one_b = less_b || b[current_bit] == 1;
    bool one_k = less_k || k[current_bit] == 1;
    // a0 b0
    long long ret = dfs(current_bit - 1, one_a, one_b, one_k);
    // a1 b0
    if (one_a)
    {
        ret += dfs(current_bit - 1, less_a, one_b, one_k);
    }
    // a0 b1
    if (one_b)
    {
        ret += dfs(current_bit - 1, one_a, less_b, one_k);
    }
    // a1 b1
    if (one_a && one_b && one_k)
    {
        ret += dfs(current_bit - 1, less_a, less_b, less_k);
    }
    return memoize[current_bit][less_a][less_b][less_k] = ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: ", i + 1);
        input();
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(k, 0, sizeof(k));
        convert(A, a);
        convert(B, b);
        convert(K, k);
        memset(memoize, -1, sizeof(memoize));
        long long ans = dfs(31, false, false, false);
        printf("%lld\n", ans);
    }
    return 0;
}
