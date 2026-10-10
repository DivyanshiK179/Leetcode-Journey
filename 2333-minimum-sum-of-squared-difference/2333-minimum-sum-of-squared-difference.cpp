#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        int maxDiff=0;
        
        vector<int> diff(n);
        for (int i=0;i<n;i++) 
        {
            diff[i]=abs(nums1[i]-nums2[i]);
            maxDiff=max(maxDiff, diff[i]);
        }
        
        vector<int> count(maxDiff+1, 0);
        for(int d:diff) 
        {
            count[d]++;
        }
        
        long long k=(long long)k1+k2;
        for(int i=maxDiff; i>0 && k>0;i--) 
        {
            if (count[i] == 0)
            {
                continue;
            }
            if(k>=count[i]) 
            {
                k-=count[i];
                count[i-1]+=count[i];
                count[i]=0;
            }
            else 
            {
                count[i-1]+=(int)k;
                count[i]-=(int)k;
                k=0;
            }
        }
        long long ans=0;
        for(int i=1; i<=maxDiff; i++) 
        {
            if(count[i]>0) 
            {
                ans+=(long long)count[i]*(long long)i*i;
            }
        }
        return ans;
    }
};