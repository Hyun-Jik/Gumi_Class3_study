import sys
from collections import deque as q
inp = sys.stdin.readline

N = (int, inp())

give = list(map(int, inp().split()))

Balloons = q(enumerate(give, start = 1))
ans = []
go_no = 0
while Balloons:
    idx, go = Balloons.popleft()

    ans.append(idx)
    if go > 0:
        Balloons.rotate(-(go-1))
    else:
        Balloons.rotate(-go)
print(*ans)