for case_num in range(int(input())):
    print('Case #%d: ' % (case_num + 1), end='')
    st = input()

    letter_count = {chr(char): st.count(chr(char)) for char in range(ord('A'),
ord('Z') + 1)}
    words = ['ZERO', 'SIX', 'SEVEN', 'FIVE', 'EIGHT', 'THREE', 'TWO', 'FOUR',
'NINE', 'ONE']
    letters = ['Z', 'X', 'S', 'V', 'G', 'H', 'T', 'F', 'I', 'O']
    numbers = [0, 6, 7, 5, 8, 3, 2, 4, 9, 1]
    ans = []

    for index, word in enumerate(words):
        number_num = letter_count[letters[index]]
        ans.extend(numbers[index] for i in range(number_num))
        for char in word:
            letter_count[char] -= number_num
    ans.sort()
    print(''.join(map(lambda x: str(x), ans)))
        
