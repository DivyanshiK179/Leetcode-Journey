/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
        int n=numsSize;
        int* prefix_prod=(int*)malloc(n*sizeof(int));
        int* suffix_prod=(int*)malloc(n*sizeof(int));
        int* ans=(int*)malloc(n*sizeof(int));
        prefix_prod[0]=1;
        for(int i=1;i<n;i++)
        {
            prefix_prod[i]=prefix_prod[i-1]*nums[i-1];
        }
        suffix_prod[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            suffix_prod[i]=suffix_prod[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++)
        {            
            ans[i]=prefix_prod[i]*suffix_prod[i];
        }
        *returnSize=n;
        return ans;
}