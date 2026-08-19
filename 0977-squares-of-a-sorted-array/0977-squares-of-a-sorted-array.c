/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
        int i=0;
        int j=numsSize-1;
        int k=numsSize-1;
        int *res=(int*)malloc(numsSize*sizeof(int));
        while(i<=j)
        {
            if(abs(nums[i])<abs(nums[j]))
            {
                res[k]=nums[j]*nums[j];
                k--;
                j--;
            }
            else
            {
                res[k]=nums[i]*nums[i];
                k--;
                i++;
            }
        }
        *returnSize=numsSize;
        return res;
}