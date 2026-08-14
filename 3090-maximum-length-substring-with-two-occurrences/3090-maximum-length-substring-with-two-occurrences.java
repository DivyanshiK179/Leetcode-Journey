class Solution {
    public int maximumLengthSubstring(String s) {
        int i=0;
        int j=0;
        int[] freq=new int[256];
        int len=s.length();
        char[] str=new char[len];
        int ans=Integer.MIN_VALUE;
        for(int k=0;k<len;k++)
        {
            str[k]=s.charAt(k);
        }
        while(j<len)
        {
            freq[str[j]]++;
            while(freq[str[j]]>2)
            {
                freq[str[i]]--;
                i++;
            }
            ans=Math.max(ans,j-i+1);
            j++;
        }
        return ans;
    }
}