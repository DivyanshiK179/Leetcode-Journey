import java.util.*;

class Solution {
    public List<String> removeInvalidParentheses(String s) {
        int remOpen=0;
        int remClose=0;

        for (char c:s.toCharArray()) 
        {
            if(c=='(') 
            {
                remOpen++;
            } 
            else if(c==')') 
            {
                if(remOpen>0) 
                {
                    remOpen--;
                } 
                else 
                {
                    remClose++;
                }
            }
        }

        Set<String> result=new HashSet<>();
        dfs(s, 0, 0, remOpen, remClose, new StringBuilder(), result);
        return new ArrayList<>(result);
    }

    private void dfs(String s, int index, int balance, int remOpen, int remClose, 
                     StringBuilder current, Set<String> result) 
    {
        if(balance<0) 
        {
            return;
        }

        if(index==s.length()) 
        {
            if(remOpen==0 && remClose==0 && balance==0) 
            {
                result.add(current.toString());
            }
            return;
        }

        char c=s.charAt(index);
        int len=current.length();

        if(c=='(' && remOpen>0) 
        {
            dfs(s, index + 1, balance, remOpen - 1, remClose, current, result);
        } 
        else if(c==')' && remClose>0) 
        {
            dfs(s, index + 1, balance, remOpen, remClose - 1, current, result);
        }

        current.append(c);
        int nextBalance=balance+(c=='('?1:(c==')'?-1:0));
        dfs(s, index + 1, nextBalance, remOpen, remClose, current, result);
        current.setLength(len);
    }
}