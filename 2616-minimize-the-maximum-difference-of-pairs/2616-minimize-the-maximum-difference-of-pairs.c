    int compare(const void *a, const void *b)
    {
        return(*(int*)a-*(int*)b);
    }
    
    bool ispossible(int *nums, int numsSize, int mid, int p)
    {
        int maxx=0;
        int pair=0;
        int i=0;
        while(i<numsSize-1)
        {
            if(ABS(nums[i+1]-nums[i])<=mid)
            {
                pair++;  
                i+=2;
            }
            else
            {
                i+=1;
            }   
        }
        if(pair>=p)
        {
            return true;
        }
        return false;
    }

int minimizeMax(int* nums, int numsSize, int p) {
        qsort(nums,numsSize,sizeof(int),compare);
        long long ans=0;
        long long s=0;
        long long e=nums[numsSize-1]-nums[0];
        while(s<=e)
        {
            long long mid=s+(e-s)/2;
            if(ispossible(nums,numsSize,mid,p))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
}