/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize) {
        int n=arrSize;
        int suffix_max=-1;
        for(int i=n-1;i>=0;i--)
        {
            int cur=arr[i];
            arr[i]=suffix_max;
            suffix_max=MAX(suffix_max,cur);
        }
        *returnSize=n;
        return arr;
}