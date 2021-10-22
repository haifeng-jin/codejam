import copy


def fill_string_with(s, start, char):
    st = copy.deepcopy(s)
    for i in range(start, len(st)):
        if st[i] == '?':
            st[i] = char
    return st


def get_value(a):
    return int(''.join(a))


def choose_ans(ans1, ans2):
    if not ans2:
        return ans1
    a = get_value(ans1[0])
    b = get_value(ans1[1])
    c = get_value(ans2[0])
    d = get_value(ans2[1])
    diff1 = abs(a - b)
    diff2 = abs(c - d)
    if diff1 != diff2:
        if diff1 > diff2:
            return ans2
        else:
            return ans1
    if a != c:
        if a < c:
            return ans1
        else:
            return ans2
    if b != d:
        if b < d:
            return ans1
        else:
            return ans2
    return ans1


def solve():
    st1, st2 = list(map(lambda x: list(x), input().split()))
    ans = (fill_string_with(st1, 0, '0'), fill_string_with(st2, 0, '0'))
    for i in range(len(st1)):
        if st1[i] != '?' and st2[i] != '?':
            if st1[i] == st2[i]:
                continue
            else:
                if st1[i] < st2[i]:
                    st1 = fill_string_with(st1, i, '9')
                    st2 = fill_string_with(st2, i, '0')
                    ans = choose_ans(ans, (st1, st2))
                    return ans
                else:
                    st1 = fill_string_with(st1, i, '0')
                    st2 = fill_string_with(st2, i, '9')
                    ans = choose_ans(ans, (st1, st2))
                    return ans
        elif st1[i] == '?' and st2[i] == '?':
            st1[i], st2[i] = '1', '0'
            s1 = fill_string_with(st1, i, '0')
            s2 = fill_string_with(st2, i, '9')
            ans = choose_ans(ans, (s1, s2))
            st1[i], st2[i] = '0', '1'
            s1 = fill_string_with(st1, i, '9')
            s2 = fill_string_with(st2, i, '0')
            ans = choose_ans(ans, (s1, s2))
            st1[i], st2[i] = '0', '0'
            continue
        else:
            if st1[i] == '?':
                temp1 = st1
                temp2 = st2
                swaped = False
            else:
                temp1 = st2
                temp2 = st1
                swaped = True
            # temp1 is the one with '?'
            if temp2[i] != '9':
                temp1[i] = chr(ord(temp2[i]) + 1)
                s1 = fill_string_with(temp1, i, '0')
                s2 = fill_string_with(temp2, i, '9')
                temp_ans = (s1, s2)
                if swaped:
                    temp_ans = (s2, s1)
                ans = choose_ans(ans, temp_ans)
            if temp2[i] != '0':
                temp1[i] = chr(ord(temp2[i]) - 1)
                s1 = fill_string_with(temp1, i, '9')
                s2 = fill_string_with(temp2, i, '0')
                temp_ans = (s1, s2)
                if swaped:
                    temp_ans = (s2, s1)
                ans = choose_ans(ans, temp_ans)
            temp1[i] = temp2[i]
            continue
    ans = choose_ans(ans, (st1, st2))
    return ans 
    

for case in range(int(input())):
    print('Case #%d: ' % (case + 1), end='')
    print(' '.join(list(map(lambda x: ''.join(x), solve()))))
