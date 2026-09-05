/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
        int n=numsSize;
        int* leftsum=(int*)malloc(n*sizeof(int));
        int* rightsum=(int*)malloc(n*sizeof(int));
        int* res=(int*)malloc(n*sizeof(int));
        for(int i=1;i<n;i++)
        {
            leftsum[i]=leftsum[i-1]+nums[i-1];
        }
        for(int j=n-2;j>=0;j--)
        {
            rightsum[j]=rightsum[j+1]+nums[j+1];
        }
        for(int i=0;i<n;i++)
        {
            res[i]=ABS(leftsum[i]-rightsum[i]);
        }
        *returnSize=n;
        return res;
}