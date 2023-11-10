import statistics
import time


def solve():
    n = int(input())
    a = [int(a_i) for a_i in input().split()]
    
    current_value = a[0]
    groups = 0
    for i in range(n):
        current_value = current_value & a[i]
        if current_value == 0:

            groups += 1

            if i < n-1:
                current_value = a[i+1]

    if groups == 0:
        groups = 1
    print(groups)

def main():
    t = int(input())

    times = []
    while t > 0:

        time_start = time.perf_counter()
        solve()
        time_duration = time.perf_counter() - time_start
        times += [time_duration * 1e6]
        t -= 1

    print("mean:",statistics.mean(times))
    print("stdev:",statistics.stdev(times))

if __name__ == "__main__":
    main()
