    bool ispossible(int *time, int timeSize, long long mid, int totalTrips)
    {
        long long t=0;
        for(int i=0;i<timeSize;i++)
        {
            t+=mid/time[i];
            if(t>=totalTrips)
            {
                return true;
            }
        }
        return false;
    }

long long minimumTime(int* time, int timeSize, int totalTrips) {
        long long ans=-1;
        long long s=1;
        long long minn=0;
        for(int i=0;i<timeSize;i++)
        {
            if(minn<time[i])
            {
                minn=time[i];
            }
        }
        long long e=minn*totalTrips;
        while(s<=e)
        {
            long long mid=(s+e)/2;
            if(ispossible(time,timeSize,mid,totalTrips))
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