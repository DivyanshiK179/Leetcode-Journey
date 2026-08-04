/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingElements(int* nums, int numsSize, int* returnSize) {
        bool contains(int nums[],int target)
        {
            for(int i=0;i<numsSize;i++)
            {
                if(nums[i]==target)
                {
                    return true;
                }
            }
            return false;
        }

        int minn=nums[0];
        int maxx=nums[0];
        for(int i=0;i<numsSize;i++)
        {
            if(nums[i]<minn)
            {
                minn=nums[i];
            }
            if(nums[i]>maxx)
            {
                maxx=nums[i];
            }
        }

        int maxposs=maxx-minn+1;
        int *res=(int*)malloc(maxposs*sizeof(int));
        int count=0;
        for(int i=minn;i<maxx;i++)
        {
            if(!contains(nums,i))
            {
                res[count++]=i;
            }
        }
        *returnSize=count;
        return res;   
}