class Solution {
    public int scoreOfParentheses(String s) {
        int score=0;
        int depth=0;
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)=='(')
            {
                depth+=1;
            }
            else
            {
                depth-=1;  
                if(s.charAt(i-1)=='(')
                {
                    score+=(1<<depth);
                }         
            }
        }
        return score;
    }
}