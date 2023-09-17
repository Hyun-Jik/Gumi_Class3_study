import sys
inp = sys.stdin.readline
from collections import deque as q

N = int(inp())
people = q(list(map(int, inp().split())))
subline = []
find = 1

for cnt in range(N):
    
    p = people[cnt]
    subline.append(p)
    while subline and subline[-1] == find:
        subline.pop()
        find += 1
        
    if len(subline) > 1 and subline[-1] > subline[-2]:
        break

if subline:
    print('Sad')
else:
    print('Nice')