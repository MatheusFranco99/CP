n = int(input())
result = "NO"


def is_lucky(n: int) -> bool:
    if all(digit in "47" for digit in str(n)):
        return True

    return False


for i in range(1, n+1):
    if is_lucky(i):
        if n % i == 0:
            result = "YES"
    
if n % 4 == 0 or n % 7 == 0:
    result = "YES"


print(result)
