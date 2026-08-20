/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultArray(int* nums, int numsSize, int* returnSize) {
        int n=numsSize;
        int arr1[n];
        int arr2[n];
        int *res=(int*)malloc(n*sizeof(int));
        arr1[0]=nums[0];
        arr2[0]=nums[1];
        int count1=1;
        int count2=1;
        for(int i=2;i<n;i++)
        {
            if(arr1[count1-1]>arr2[count2-1])
            {
                arr1[count1]=nums[i];
                count1++;
            }
            else
            {
                arr2[count2]=nums[i];    
                count2++;           
            }
        }
        for(int i=0;i<count1;i++)
        {
            res[i]=arr1[i];
        }
        for(int j=0;j<count2;j++)
        {
            res[count1+j]=arr2[j];
        }
        *returnSize=n;
        return res;
}