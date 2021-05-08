h, w, a, b = map(int, input().split())
d = 0
# https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
mod = 10**9+7


def root_comb(x, y):
    return mod_fractal(x+y, x)/mod_fractal(y, 1) % mod


def mod_fractal(a1, a2):
    s = 1
    for i in range(a1, a2, -1):
        s = s * i % mod
    return s


for i in range(h-a):
    d += root_comb(i, b-1) * root_comb(h-i-1, w-b-1) % mod
print(int(d))
