# 별찍기 - 16
import sys
n = int(sys.stdin.readline())

for i in range(1, n+1):
    # 맨 앞 공백
    for j in range(n-i):
        print(' ', end='')
    # 별 + 공백 for n times
    for k in range(i):
        print('* ', end='')
    print()