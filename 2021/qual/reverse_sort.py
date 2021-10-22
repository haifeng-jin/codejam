def solve():
    n = int(input())
    seq = list(map(int, input().split()))
    ret = 0
    for i in range(n-1):
        j = seq.index(i + 1) 
        ret += j - i + 1
        seq[i:j + 1] = reversed(seq[i:j+1])
    return ret
    
t = int(input())
for i in range(t):
    print(f"Case #{i+1}: {solve()}")
