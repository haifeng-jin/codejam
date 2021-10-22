def solve(x, y, s):
    f = [[1<<63, 1<<63] for i in range(len(s))]
    if s[0] in ["?", "C"]:
        f[0][0] = 0
    if s[0] in ["?", "J"]:
        f[0][1] = 0

    for i in range(1, len(s)):
        if s[i] in ["?", "C"]:
            f[i][0] = min(f[i-1][0], f[i-1][1] + y)
        if s[i] in ["?", "J"]:
            f[i][1] = min(f[i-1][1], f[i-1][0] + x)
    return min(f[len(s) - 1][0], f[len(s) - 1][1])


if __name__ == "__main__":
    num_cases = int(input())
    for i in range(num_cases):
        x, y, s = input().split()
        print(f"Case #{i + 1}: {solve(int(x), int(y), s)}")
