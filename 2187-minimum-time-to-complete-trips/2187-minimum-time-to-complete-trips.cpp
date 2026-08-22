class Solution {
    bool ispossible(vector<int>& time, long long mid, int totalTrips)
    {
        long long t=0;
        for(int i=0;i<time.size();i++)
        {
            t+=mid/time[i];
            if(t>=totalTrips)
            {
                return true;
            }
        }
        return false;
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans=-1;
        long long s=1;
        long long minn=0;
        for(int i=0;i<time.size();i++)
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
            if(ispossible(time,mid,totalTrips))
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
};