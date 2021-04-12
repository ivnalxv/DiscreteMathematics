n = int(input())
code = list(map(int, input().split()))
n = len(code)

mp = []

for c in range(ord('a'), ord('z') + 1):
    mp.append(chr(c))

x = code[0]
res = str(mp[x])
mp.append(mp[x])

for i in range(1, n):
    y = code[i]
    if y < len(mp):
        mp[-1] = mp[-1] + mp[y][0]
        mp.append(mp[y])
        res = res + mp[y]
    else:
        mp[-1] = mp[-1] + mp[-1][0]
        res = res + mp[-1]
        mp.append(mp[-1])


print(res)