for case in range(int(input())):
    print('Case #%d: ' % (case + 1), end='')
    n, m = map(int, input().split())
    if m > 2 ** (n - 2):
        print('IMPOSSIBLE')
        continue
    print('POSSIBLE')
    if m == 2 ** (n - 2):
        temp = ['0']
        temp.extend(['1' for i in range(n - 1)])
        print(''.join(temp))
    else:
        x = m
        f = '{0:0%db}' % (n - 1)
        temp = [f.format(m)]
        temp.append('0')
        print(''.join(temp))
    for i in range(n - 1):
        temp = ['0' for j in range(i + 2)]
        temp.extend(['1' for j in range(n - i - 2)])
        print(''.join(temp))
