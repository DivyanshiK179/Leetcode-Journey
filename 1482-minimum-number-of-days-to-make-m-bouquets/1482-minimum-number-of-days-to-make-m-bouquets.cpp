class Solution {
    bool ispossible(vector<int> &bloomDay, int mid, int m, int k)
    {
        int bouquet=0;
        int count=0;
        for(int i=0;i<bloomDay.size();i++)
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
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size())
        {
            return -1;
        }
        int ans=-1;
        int s=1;
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++)
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
            if(ispossible(bloomDay,mid,m,k))
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