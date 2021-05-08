n = int(input())
i = [list(map(int, input().split())) for i in range(n)]
s = [0] * 3
for e in i:
    dt = e[0] - s[0]
    dx = e[1] - s[1]
    dy = e[2] - s[2]
    if abs(dx) + abs(dy) > dt or (dx + dy) % 2 != dt % 2:
        print("No")
        exit()
    s = e
print("Yes")
