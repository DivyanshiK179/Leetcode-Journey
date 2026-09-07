class Solution {
    private void solve(int n, List<String> res, int open, int close, String s)
    {
        if(open==n && close==n)
        {
            res.add(s);
            return;
        }
        if(close>open || open>n)
        {
            return;
        }
        solve(n,res,open+1,close,s+"(");
        solve(n,res,open,close+1,s+")");
    }

    public List<String> generateParenthesis(int n) {
        List<String> res= new ArrayList<>();
        solve(n, res, 0, 0, "");
        return res;
    }
}