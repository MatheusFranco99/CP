def matrix(rows, cols):
    m = [[0] * cols for _ in range(rows)] # gpt

    for i in range(rows):
        for j in range(cols):
            if i == 0 or j == 0:
                m[i][j] = 1
            else:
                m[i][j] = m[i - 1][j] + m[i][j - 1]
    return m


n = int(input())

m: list = matrix(n, n)

print(m[-1][-1])
