input_a = str(input()).strip("{}")

a = [element.strip() for element in input_a.split(",")]

b: set = set(a)

if a[0] == "":
    print(0)
else:
    print(b.__len__())
