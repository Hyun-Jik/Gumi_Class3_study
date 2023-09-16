# 별 찍기 - 17
n = int(input())

for i in range(n-1):
    # i 번째 줄의 출력
    # 첫 별이 등장하기 전의 공백 갯수
    print(' ' * (n-1-i), end='')
    # 첫 별 등장
    print('*', end='')
    # 다음 별이 나오기 전의 공백 갯수
    print(' ' * (2 * i - 1), end='')
    if i != 0:
        print('*', end='')
    print()


# 마지막 줄은 따로 빼서 출력하자
print('*' * (2*n-1))
