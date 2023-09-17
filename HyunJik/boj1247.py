# 작성 안 하면 시간 초과 뜸
import sys
input = sys.stdin.readline

# 총 3개의 테스트 셋이 주어지므로
for _ in range(3):
    # 테스트 셋의 첫째 줄
    N = int(input())
    # 한 줄에 한 숫자씩, N개 줄에 걸쳐 주어짐
    list = [int(input()) for i in range(N)]
    if sum(list) == 0:
        print('0')
    elif sum(list) > 0:
        print('+')
    else:
        print('-')