int compare(const void *a,const void *b)
{
    return (*(int*)a-*(int*)b);
}

bool check(int* nums, int numsSize) {
        int *A=(int*)malloc(numsSize*sizeof(int));
        for(int i=0;i<numsSize;i++)
        {
            A[i]=nums[i];
        }
        qsort(A,numsSize,sizeof(int),compare);
        for(int x=0;x<numsSize;x++)
        {
            bool is_match=true;
            for(int i=0;i<numsSize;i++)
            {
                if(A[i]!=nums[(i+x)%numsSize])
                {
                    is_match=false;
                    break;
                }
            }
            if(is_match)
            {
                return true;
            }
        }
        return false;
}