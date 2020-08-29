#https://algotester.com/en/ArchiveProblem/DisplayWithEditor/40194
import sys
sys.setrecursionlimit(100000000)
N,M = [int(i) for i in input().split()]
A,B = [int(i) for i in input().split()]

graph = [[] for i in range(N+1)]
for i in range(M):
  a,b = [int(i) for i in input().split()]
  graph[b].append(a)

w = [0 for i in range(N+1)]

d = [0 for i in range(N+1)]

d[A]=1
w[A]=1

def dfs(v):
  if w[v]==1:
    return d[v]
  else:
    suma = 0
    w[v]=1
    for i in graph[v]:
      suma+= dfs(i)
    d[v]+=suma%1234567891
    return suma
dfs(B)
print(d[B]%1234567891)


