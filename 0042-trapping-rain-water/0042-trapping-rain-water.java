class Solution {
    public int trap(int[] height) {
        int n=height.length;
        int[] prefix_max=new int[n];
        int[] suffix_max=new int[n];
        int water=0;
        prefix_max[0]=height[0];
        for(int i=1;i<n;i++)
        {
            prefix_max[i]=Math.max(prefix_max[i-1],height[i]);
        }
        suffix_max[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix_max[i]=Math.max(suffix_max[i+1],height[i]);
        }
        for(int i=0;i<n;i++)
        { 
            water+=Math.min(prefix_max[i],suffix_max[i])-height[i];
        }
        return water;
    }
}