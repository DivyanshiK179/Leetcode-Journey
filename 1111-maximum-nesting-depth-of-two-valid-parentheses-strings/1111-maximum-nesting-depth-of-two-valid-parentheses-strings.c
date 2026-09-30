#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char* seq, int* returnSize) 
{
    int n=strlen(seq);
    *returnSize=n;
    
    int* ans=(int*)malloc(n*sizeof(int));
    if (ans==NULL)
    {
        return NULL;
    }
    
    int depth=0;
    for (int i=0;i<n;i++) {
        if (seq[i]=='(') {
            depth++;
            ans[i]=depth%2;
        } else {
            ans[i]=depth%2;
            depth--;
        }
    }
    
    return ans;
}