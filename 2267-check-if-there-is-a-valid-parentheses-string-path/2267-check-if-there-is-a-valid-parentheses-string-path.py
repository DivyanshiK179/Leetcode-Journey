from functools import cache

class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        m, n = len(grid), len(grid[0])

        if (m + n - 1) % 2 != 0:
            return False
        
        if grid[0][0] != '(' or grid[m - 1][n - 1] != ')':
            return False
        
        max_bal = (m + n - 1) // 2
        
        @cache
        def dfs(r: int, c: int, bal: int) -> bool:
            if bal < 0 or bal > max_bal:
                return False
    
            if r == m - 1 and c == n - 1:
                return bal == 0

            for dr, dc in ((1, 0), (0, 1)):
                nr, nc = r + dr, c + dc
                if nr < m and nc < n:
                    delta = 1 if grid[nr][nc] == '(' else -1
                    if dfs(nr, nc, bal + delta):
                        return True
            
            return False
        
        return dfs(0, 0, 1)