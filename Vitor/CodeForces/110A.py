n = int(input())

ln = 0

for _, v in enumerate(str(n)):
    if v == "4" or v == "7":
        ln += 1

if ln == 4 or ln == 7:
    print("YES")
else:
    print("NO")
