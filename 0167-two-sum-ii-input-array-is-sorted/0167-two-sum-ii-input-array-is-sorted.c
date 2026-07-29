/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *res=(int*)malloc(2*sizeof(int));
        int i=0;
        int j=numbersSize-1;
        while(i<j)
        {
            if((numbers[i]+numbers[j])==target)
            {
                res[0]=i+1;
                res[1]=j+1;
                *returnSize=2;
                break;
            }
            else if(numbers[i]+numbers[j]>target)
            {
                j--;
            }
            else if(numbers[i]+numbers[j] < target)
            {
                i++;
            }
        }
        return res;
}