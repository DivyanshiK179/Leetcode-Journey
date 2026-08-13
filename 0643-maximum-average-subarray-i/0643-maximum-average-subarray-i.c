double findMaxAverage(int* nums, int numsSize, int k) {
        int i=0;
        int j=0;
        double sum=0;
        double maxi=INT_MIN;
        while(j<numsSize)
        {
            sum+=nums[j];
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                maxi=MAX(sum,maxi);
                sum-=nums[i];
                i++;
                j++;
            }
        }
        return maxi/k;
}