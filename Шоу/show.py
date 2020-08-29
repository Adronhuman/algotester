import sys
n = int(input())
gluck = sorted([int(i) for i in input().split()])[::-1]
margaritka = sorted([int(i) for i in input().split()])[::-1]

temp_1 = [0]*11
temp_2 = [0]*11

for i in gluck:
    temp_1[i] +=1
for i in margaritka:
    temp_2[i] +=1

rez_g = rez_m = 1

for i in range(1,11):
  m = min(temp_1[i],temp_2[i])
  temp_1[i] -= m
  temp_2[i] -= m
  rez_g *= i**temp_1[i]
  rez_m *= i ** temp_2[i]

if rez_g> rez_m:
  print("Gluk")
  sys.exit(0)
elif rez_m > rez_g:
  print("Margaritka")
  sys.exit(0)
else:
  for i in range(n):
    if gluck[i]>margaritka[i]:
      print("Gluk")
      sys.exit(0)
    if margaritka[i] > gluck[i]:
      print("Margaritka")
      sys.exit(0)
print("Margaritka")

