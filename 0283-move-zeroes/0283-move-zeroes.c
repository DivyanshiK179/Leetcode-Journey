void moveZeroes(int* nums, int numsSize) {
        int i=0;
        for(int j=0;j<numsSize;j++)
        {
            if(nums[j]!=0)
            {
                int temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
                i++;
            }
        }
}