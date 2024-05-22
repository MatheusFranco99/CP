def sum_digits(part: str) -> int:
    x = 0
    for _, v in enumerate(part):
        x += int(v)

    return x


def func(ticket: str):
    first = sum_digits(ticket[:3])
    last = sum_digits(ticket[3:])

    if first == last:
        print("YES")
    else:
        print("NO")


def main():
    t = int(input())

    for i in range(t):
        ticket = str(input())
        func(ticket=ticket)


if __name__ == "__main__":
    main()
