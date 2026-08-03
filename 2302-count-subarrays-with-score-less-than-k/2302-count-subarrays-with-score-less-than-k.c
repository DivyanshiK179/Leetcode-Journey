long long countSubarrays(int* nums, int numsSize, long long k) {
        int i=0;
        int j=0;
        long long sum=0;
        long long score=0;
        long long count=0;
        while(j<numsSize)
        {
            sum+=nums[j];
            score=sum*(j-i+1);
            while(score>=k && i<=j)
            {
                sum-=nums[i];
                i++;
                score=sum*(j-i+1);
            }
            count+=(j-i+1);
            j++;
        }
        return count;
}