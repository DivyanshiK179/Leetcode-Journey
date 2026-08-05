class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] freq=new int[256];
        for(int i=0;i<256;i++)
        {
            freq[i]=0;
        }
        int j=0;
        int i=0;
        int max_win=0;
        while(j<s.length())
        {
            while(freq[s.charAt(j)]==1)
            {
                freq[s.charAt(i)]=0;
                i++;
            }
            freq[s.charAt(j)]=1;
            int cur_win=j-i+1;
            max_win=Math.max(max_win,cur_win);
            j++;
        }
        return max_win;
    }
}