n, k = map(int, input().split())
d = list(map(int, input().split()))
u = list(set(list(range(10))) - set(d))
for i in range(n, 10**5):
    if len(list(set(list(map(int, str(i)))) - set(u))) != 0:
        continue
    print(i)
    exit()
