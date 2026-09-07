class Solution:
    def solve(self, n: int, res: List[str], open: int, close: int, s: str):
        if(open==n and close==n):
            res.append(s)
            return
        if(close>open or open>n):
            return
        self.solve(n,res,open+1,close,s+"(")
        self.solve(n,res,open,close+1,s+")")
        
    def generateParenthesis(self, n: int) -> List[str]:
        res=[]
        self.solve(n, res, 0, 0, "")
        return res