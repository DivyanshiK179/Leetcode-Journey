class Solution {
    public int[] replaceElements(int[] arr) {
        int n=arr.length;
        int suffix_max=-1;
        for(int i=n-1;i>=0;i--)
        {
            int cur=arr[i];
            arr[i]=suffix_max;
            suffix_max=Math.max(suffix_max,cur);
        }
        return arr;
    }
}