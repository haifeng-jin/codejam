def cal(selected, m):
    dp = [[0 * i * j for j in range(m + 3)] for i in range(m + 3)]
    dp[0][0] = 1
    for i in range(0, m):
        for j in range(0, i + 1):
            dp[i + 1][j + 1] += dp[i][j] * selected[i]
            dp[i + 1][j] += dp[i][j] * (1.0 - selected[i])
    return dp[m][int(m/2)]


def solve():
    n, m = map(int, input().split())
    f = list(map(float, input().split()))
    f.sort()
    ans = 0
    for i in range(m + 1):
        selected = f[0:i]
        selected.extend(f[-(m - i):])
        ans = max(ans, cal(selected, m))
    return ans


for case in range(int(input())):
    print('Case #%d: %.7f' % (case + 1, solve()))
