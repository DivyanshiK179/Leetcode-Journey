class Solution {
    private boolean isPalindrome(String s, int i, int j)
    {
        while(i<j)
        {
            if(s.charAt(i)!=s.charAt(j))
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(String s, List<List<String>> output, List<String> temp, int i)
    {
        //base case
        if(i==s.length())
        {
            output.add(new ArrayList<>(temp));
            return;
        }
        for(int j=i;j<s.length();j++)
        {
            if(isPalindrome(s, i, j))
            //do partition
            {
                temp.add(s.substring(i, j+1));
                solve(s, output, temp, j+1);
                //bactrack
                temp.remove(temp.size()-1);
            }
        }
    }
    public List<List<String>> partition(String s) {
        List<List<String>> output=new ArrayList<>();
        List<String> temp=new ArrayList<>();
        solve(s, output, temp, 0);
        return output;
    }
}