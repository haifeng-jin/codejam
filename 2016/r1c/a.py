def to_chars(letters):
    letters = [chr(ord('A') + letter) for letter in letters]
    return ''.join(letters)


for case in range(int(input())):
    print('Case #%d: ' % (case + 1), end='')
    n = int(input())
    f = list(map(int, input().split()))
    ans = []
    while sum(f) != 0:
        temp_ans = []
        if f.count(max(f)) == 2:
            index = f.index(max(f))
            f[index] -= 1
            temp_ans.append(index)
        index = f.index(max(f))
        f[index] -= 1
        temp_ans.append(index)
        ans.append(temp_ans)
    print(' '.join(map(to_chars, ans)))
