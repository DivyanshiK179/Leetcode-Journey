#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int n=nums.size();
        if (n<=1)
        {
            return 0;
        }

        int idx=0;
        for(int i=0;i<n;++i) 
        {
            if(nums[i]==0) 
            {
                idx=i;
                break;
            }
        }

        bool is_inc=true;
        for(int i=0;i<n;++i) 
        {
            if(nums[(idx+i)%n]!=i) 
            {
                is_inc=false;
                break;
            }
        }

        if(is_inc) 
        {
            if(idx==0)
            { 
                return 0;
            }
            return min(idx,n-idx+2);
        }

        bool is_dec=true;
        for(int i=0;i<n;++i) 
        {
            if(nums[(idx-i+n)%n]!=i) 
            {
                is_dec=false;
                break;
            }
        }

        if(is_dec) 
        {
            int op1=n-idx;
            int op2=((idx+1)%n)+1;
            return min(op1,op2);
        }

        return -1;
    }
};