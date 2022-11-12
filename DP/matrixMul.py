
maxint = float('inf')


def MatrixChainOrder(P: list[int], n: int):
    dp: list[list[float]]

    # number of matrixes are n-1 and as its 1 based indexing so 1
    # Req. to run looks from 1 to n-1
    dp = [[maxint for _ in range(n)] for _ in range(n)]

    for i in range(1, n):
        dp[i][i] = 0

    for i in range(1, n):  # i in range [1, n-1]
    
        for j in range(1, n - i+1):  # j in range [1, n-i-1]

            for k in range(j, j + i - 1):  # k in range [j, j+i-1]
        
                t = dp[j][k] + dp[k + 1][j + i - 1] + P[j-1] * P[k] * P[j + i - 1]
                if t < dp[j][j + i-1]:
                    dp[j][j + i-1] = t

    for i in range(1, n):
        print(dp[i])

    return dp[1][n - 1]


if __name__ == "__main__":
    #arr: list[int] = [1, 2, 3, 4]  # size ranges of all the matrix mat01 mat02 mat03
    arr: list[int] = [30,35, 15, 5 ,10, 20, 25]  # size ranges of all the matrix mat01 mat02 mat03
    size: int = len(arr)
    print(MatrixChainOrder(arr, size))
