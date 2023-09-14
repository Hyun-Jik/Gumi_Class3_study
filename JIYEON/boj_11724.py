# 연결 요소의 개수
def bfs(v):
    visited[v] = 1
    need_visit.append(v)
    while need_visit:
        tmp = need_visit.popleft()
        for i in graph[tmp]:
            if visited[i] == 0:
                visited[i] = 1
                need_visit.append(i)

import sys
from collections import deque
n, m = map(int, sys.stdin.readline().strip().split())

graph = [[] for _ in range(n+1)]
for i in range(m):
    u, v = map(int, sys.stdin.readline().strip().split())
    graph[u].append(v)
    graph[v].append(u)

need_visit = deque()
visited = [-1] + [0] * n

cnt = 0

while 0 in visited:
    cnt += 1
    bfs(visited.index(0))

print(cnt)