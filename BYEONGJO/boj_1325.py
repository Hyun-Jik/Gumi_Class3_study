import sys
from collections import deque as q
inp = sys.stdin.readline

def BFS(i):
    hacking = 1
    visit = [False for _ in range(n)]
    Q = q([i])
    visit[i] = True
    while Q:
        v = Q.popleft()
        for r in roots[v]:
            if not visit[r]:
                visit[r] = True
                Q.append(r)
                hacking += 1
    return hacking

N, M = map(int, inp().split())
n = N + 1

roots = [[] for _ in range(n)]

for _ in range(M):
    A, B = map(int, inp().split())
    roots[B].append(A)

mx_cnt = 0
ans = []

for i in range(1, n):
    cnt = BFS(i)
    if mx_cnt < cnt:
        mx_cnt = cnt
        ans.clear()
        ans.append(i)
    elif mx_cnt == cnt:
        ans.append(i)

print(*ans)