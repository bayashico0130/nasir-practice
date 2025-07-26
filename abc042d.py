h, w, a, b = map(int, input().split())
d = 0
# https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
mod = 10**9+7


def init_fractal_store(x1):
    frac = {}
    finv = {}
    inv = {}
    frac[0] = frac[1] = inv[1] = finv[0] = finv[1] = 1
    for i in range(2, x1):
        frac[i] = frac[i-1] * i % mod
        inv[i] = mod - inv[mod % i] * (mod/i) % mod
        finv[i] = finv[i-1] * inv[i] % mod
    return frac, finv


def root_comb(x, y, mf, fi):
    # return mod_fractal(x+y, x)/mod_fractal(y, 1) % mod
    return mf[x+y] * (fi[x] * fi[y] % mod) % mod


def mod_fractal(a1, a2):
    s = 1
    for i in range(a1, a2, -1):
        s = s * i % mod
    return s


mf, fi = init_fractal_store(h+w)
for i in range(h-a):
    d += root_comb(i, b-1, mf, fi) * root_comb(h-i-1, w-b-1, mf, fi) % mod
    d %= mod
print(int(d))
