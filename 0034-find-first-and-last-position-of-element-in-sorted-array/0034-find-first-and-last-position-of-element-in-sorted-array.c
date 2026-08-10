/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int lower_bound(int nums[],int target,int size)
{
    int s=0;
    int e=size-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(nums[mid]==target)
        {
            ans=mid;
            e=mid-1;
        }
        else if(nums[mid]<target)
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return ans;  
}  

int upper_bound(int nums[],int target,int size)
{
    int s=0;
    int e=size-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(nums[mid]==target)
        {
            ans=mid;
            s=mid+1;;
        }
        else if(nums[mid]<target)
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return ans;  
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
        int *res=(int*)malloc(2*sizeof(int));
        int l=lower_bound(nums,target,numsSize);
        res[0]=l; 
        int u=upper_bound(nums,target,numsSize); 
        res[1]=u;
        *returnSize=2; 
        return res;
}