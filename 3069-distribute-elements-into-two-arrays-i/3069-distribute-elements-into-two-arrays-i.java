class Solution {
    public int[] resultArray(int[] nums) {
        int n=nums.length;
        int[] arr1=new int[n];
        int[] arr2=new int[n];
        int[] res=new int[n];      
        arr1[0]=nums[0];
        arr2[0]=nums[1];
        int count1=1;
        int count2=1;
        for(int i=2;i<n;i++)
        {
            if(arr1[count1-1]>arr2[count2-1])
            {
                arr1[count1]=nums[i];
                count1++;
            }
            else
            {
                arr2[count2]=nums[i];    
                count2++;           
            }
        }
        for(int i=0;i<count1;i++)
        {
            res[i]=arr1[i];
        }
        for(int j=0;j<count2;j++)
        {
            res[count1+j]=arr2[j];
        }
        return res;
    }
}