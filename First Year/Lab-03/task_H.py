import math

m = int(input())
n = 0

alph = []
for i in range(m):
    alph.append(chr(ord('a') + i))

prob = list(map(int, input().split()))
for i in prob:
    n += i

bins = input()

p = int(bins, 2)
qq = 1
for i in range(len(bins)):
    qq *= 2

res = ""

for i in range(n):
    for j in range(m):
        l = 0
        r = 1
        z = n
        for ch in range(0, j):
            l += prob[ch]
        r = l + prob[j]

        if (l * qq <= p * n and p * n < r * qq):
            res += str(chr(j + ord('a')))
            p = p*z - l*qq
            qq = (r - l)*qq
            gcd = math.gcd(p, qq)
            p = p//gcd
            qq = qq//gcd
            break

print(res)