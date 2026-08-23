    bool ispossible(int *bloomDay, int bloomDaySize, int mid, int m, int k)
    {
        int bouquet=0;
        int count=0;
        for(int i=0;i<bloomDaySize;i++)
        {
            if(bloomDay[i]<=mid)
            {
                count++;
                if(count==k)
                {
                    bouquet++;
                    count=0;
                }     
            }
            else
            {
                count=0;
            }
        }
        if(bouquet>=m)
        {
            return true;
        }
        return false;
    }

int minDays(int* bloomDay, int bloomDaySize, int m, int k) {
        if((long long)m*k>bloomDaySize)
        {
            return -1;
        }
        int ans=-1;
        int s=1;
        int maxi=INT_MIN;
        for(int i=0;i<bloomDaySize;i++)
        {
            if(bloomDay[i]>maxi)
            {
                maxi=bloomDay[i];
            }
        }
        int e=maxi;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(ispossible(bloomDay,bloomDaySize,mid,m,k))
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