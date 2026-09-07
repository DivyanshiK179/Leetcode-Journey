class Solution {
    private:
    void solve(int n, vector<string> &res, int open, int close, string s)
    {
        if(open==n && close==n)
        {
            res.push_back(s);
            return;
        }
        if(close>open || open>n)
        {
            return;
        }
        solve(n,res,open+1,close,s+"(");
        solve(n,res,open,close+1,s+")");
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(n, res, 0, 0, "");
        return res;
    }
};