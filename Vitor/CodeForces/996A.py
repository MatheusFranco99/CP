"""
Usar os múltiplos das notas
"""

from math import floor

n = int(input())

t: int = 0

while True:
    if n == 0:
        break

    if n >= 100:
        divisao = n / 100

        n -= 100 * floor(divisao) # Só o 100 multiplica: lidar com números muito grandes
        t += floor(divisao)
        continue
    elif n >= 20:
        t += 1
        n -= 20

        continue
    elif n >= 10:
        t += 1
        n -= 10

        continue
    elif n >= 5:
        t += 1
        n -= 5

        continue
    else:
        t += 1
        n -= 1

        continue

print(t)
