class Solution {
    public boolean uniformArray(int[] nums1) {
        int minVal=nums1[0];
        boolean hasOdd=false;

        for (int x:nums1) {
            if (x<minVal) {
                minVal=x;
            }
            if (x%2!=0) {
                hasOdd=true;
            }
        }
        return (minVal%2!=0)||!hasOdd;
    }
}