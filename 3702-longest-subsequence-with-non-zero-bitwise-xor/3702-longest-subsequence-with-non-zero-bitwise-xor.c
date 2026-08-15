int longestSubsequence(int* nums, int numsSize) {
    int total_xor=0;
    int has_nz=0;
    for(int i=0;i<numsSize;i++)
    {
        total_xor^=nums[i];
        if(nums[i]!=0)
        {
            has_nz=1;
        }
    }
    if(total_xor!=0)
    {
        return numsSize;
    }
    else if(has_nz)
    {
        return numsSize-1;
    }
    return 0;
}