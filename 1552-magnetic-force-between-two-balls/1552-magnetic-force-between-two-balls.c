bool ispossible(int *position,int positionSize,int mid,int m){
    int ball=1;
    int pos=position[0];
    for(int i=1;i<positionSize;i++)
    {
        if(position[i]-pos>=mid)
        {
            ball++;
            pos=position[i];
        }
        if(ball==m)
        {
            return true;
        }
    }
    return false;
}

int compare(const void *a,const void *b)
{
    return (*(int*)a-*(int*)b);
}

int maxDistance(int* position, int positionSize, int m) {
        qsort(position,positionSize,sizeof(int),compare);
        int ans=-1;
        int s=1;
        int e=position[positionSize-1]-position[0];
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(ispossible(position,positionSize,mid,m))
            {
                ans=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return ans;
}