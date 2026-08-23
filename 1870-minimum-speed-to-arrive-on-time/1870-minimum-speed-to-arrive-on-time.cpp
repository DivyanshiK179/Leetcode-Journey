class Solution {
    bool ispossible(vector<int> &dist, long long mid, double hour)
    {
        double h=0;
        int n=dist.size();
        for(int i=0;i<n-1;i++)
        {
            h+=(dist[i]+mid-1)/mid;
        }
        h+=(double)dist[n-1]/mid;
        if(h<=hour)
        {
            return true;
        }
        return false;
    }

public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        long long ans=-1;
        long long s=1;
        long long e=1e7;
        while(s<=e)
        {
            long long mid=s+(e-s)/2;
            if(ispossible(dist,mid,hour))
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