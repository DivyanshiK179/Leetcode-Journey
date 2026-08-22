class Solution {
    bool ispossible(vector<int> &ranks, long long mid , int cars)
    {
        long long c=0;
        for(int i=0;i<ranks.size();i++)
        {
            c+=sqrt(mid/ranks[i]);
            if(c>=cars)
            {
                return true;
            }
        }
        return false;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long s=1;
        long long minn=INT_MAX;
        for(int i=0;i<ranks.size();i++)
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
            if(ispossible(ranks,mid,cars))
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