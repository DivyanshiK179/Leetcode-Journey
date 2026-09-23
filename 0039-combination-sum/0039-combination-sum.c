/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void solve(int *candidates, int candidatesSize, int target, int ***answer, int** returnColumnSizes, int* returnSize, int *capacity, int *temp, int tempSize, int  i)
{
        if(target==0)
        {
            if(*returnSize>=*capacity)
            {
                *capacity*=2;
                *answer=(int**)realloc(*answer,(*capacity)*sizeof(int*));
                *returnColumnSizes=(int*)realloc(*returnColumnSizes,(*capacity)*sizeof(int));
            }
            (*answer)[*returnSize]=(int*)malloc(tempSize*sizeof(int));
            for (int k=0; k<tempSize;k++) 
            {
                (*answer)[*returnSize][k]=temp[k];
            }
            (*returnColumnSizes)[*returnSize]=tempSize;
            (*returnSize)++;
            return;
        }
        if(i==candidatesSize)
        {
            return;
        }
        if(candidates[i]<=target)
        {
            temp[tempSize]=candidates[i];
            solve(candidates,candidatesSize,target-candidates[i],answer,returnColumnSizes,returnSize,capacity,temp,tempSize+1,i);
        }
        solve(candidates,candidatesSize,target,answer,returnColumnSizes,returnSize,capacity,temp,tempSize,i+1);
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int capacity=100;
    int** answer=(int**)malloc(capacity*sizeof(int*));    
    *returnColumnSizes=(int*)malloc(capacity*sizeof(int));
    *returnSize=0;
    int *temp=(int*)malloc((target+1)*sizeof(int));
    solve(candidates, candidatesSize, target, &answer, returnColumnSizes, returnSize, &capacity,temp, 0, 0);
    free(temp);
    return answer;
}