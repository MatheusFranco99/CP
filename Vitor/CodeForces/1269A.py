"""
          (a,  b) -> a - b = n
n = 10 -> (14, 4) (16, 6) (18, 8) (20, 10) (22, 12) (24, 14)...

(a  ,   b)
(n + b, b) tal que n, a não primos
a >= 2

"""


n = int(input())

# def e_primo(num):
#     soma = 0
#     for i in range(2, num):
#         if num % i == 0:
#             return False
#     return True

# b = 2
# a = n + b
# while True:
#     if e_primo(b) or e_primo(a):
#         b += 1
#         a += 1
#     else:
#         print(a,b)
#         break


if n == 1:
    print(9, 8)
else:
    print(3*n, 2*n)

# n
# 3n, 2n