    bool ispossible(int *piles, int pilesSize , int mid , int h)
    {
        int hour=0;
        for(int i=0;i<pilesSize;i++)
        {
            if(piles[i]<=mid)
            {
                hour++;
            }
            else if(piles[i]%mid==0)
            {
                hour+=(piles[i]/mid);
            }
            else if(piles[i]%mid!=0)
            {
                hour+=(piles[i]/mid)+1;
            }
            if(hour>h)
            {
                return false;
            }
        }
        return true;
    }

int minEatingSpeed(int* piles, int pilesSize, int h) {
        int ans=-1;
        int s=1;
        int maxi=INT_MIN;
        for(int i=0;i<pilesSize;i++)
        {
            if(piles[i]>maxi)
            {
                maxi=piles[i];
            }
        }
        int e=maxi;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(ispossible(piles,pilesSize,mid,h))
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