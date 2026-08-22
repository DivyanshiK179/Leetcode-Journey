    bool ispossible(int *ranks, int ranksSize, long mid, int cars)
    {
        long long c=0;
        for(int i=0;i<ranksSize;i++)
        {
            c+=sqrt(mid/ranks[i]);
            if(c>=cars)
            {
                return true;
            }
        }
        return false;
    }

long long repairCars(int* ranks, int ranksSize, int cars) {
        long long s=1;
        long long minn=INT_MAX;
        for(int i=0;i<ranksSize;i++)
        {
            if(ranks[i]<minn)
            {
                minn=ranks[i];
            }
        }
        long long e=minn*cars*cars;
        long long ans=e;
        while(s<=e)
        {
            long long mid=(s+e)/2;
            if(ispossible(ranks,ranksSize,mid,cars))
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