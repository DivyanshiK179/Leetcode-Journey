class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> subarray_count(51,0);
        vector<int> freq(51,0);
        int i=0;
        int j=0;
        int maxi=-1;
        while(j<nums.size())
        {
            freq[nums[j]]++;
            if(j-i+1==k)
            {
                for(int i=0;i<51;i++)
                {
                    if(freq[i]>0)
                    {
                        subarray_count[i]++;
                    }
                }
                freq[nums[i]]--;
                i++;
            }
            j++;
        }
        for(int i=0;i<51;i++)
        {
            if(subarray_count[i]==1)
            {
                maxi=max(maxi,i);
            }
        }
        return maxi;
    }
};