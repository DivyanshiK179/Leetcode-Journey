class Solution {
    public int largestAltitude(int[] gain) {
        int high=0;
        int height=0;
        for(int i=0;i<gain.length;i++)
        {
            height+=gain[i];
            high=Math.max(high,height);
        }
        return high;
    }
}