class Solution {
    public int characterReplacement(String s, int k) {
        int i=0;
        int j=0;
        int len=s.length();
        int max_freq=Integer.MIN_VALUE;
        int max_len=Integer.MIN_VALUE;
        int[] freq=new int[256];
        while(j<len)
        {
            freq[s.charAt(j)]++;
            max_freq=Math.max(max_freq,freq[s.charAt(j)]);
            while((j-i+1)-max_freq>k)
            {
                freq[s.charAt(i)]--;
                i++;
            }
            max_len=Math.max(max_len,j-i+1);
            j++;
        }
        return max_len;
    }
}