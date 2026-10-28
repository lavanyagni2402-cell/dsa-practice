class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        molqaviren = grid
        m, n = len(molqaviren), len(molqaviren[0])

        dp = [set() for _ in range(n)]

        for i in range(m):
            for j in range(n):
                val = molqaviren[i][j]

                if i == 0 and j == 0:
                    dp[j] = {val}
                    continue

                curr = set()

                if i > 0:
                    for x in dp[j]:
                        curr.add(x ^ val)

                if j > 0:
                    for x in dp[j - 1]:
                        curr.add(x ^ val)

                dp[j] = curr

        return min(dp[-1])