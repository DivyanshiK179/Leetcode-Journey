class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> A=nums;
        sort(A.begin(),A.end());
        int n=nums.size();
        for(int x=0;x<n;x++)
        {
            bool is_match=true;
            for(int i=0;i<n;i++)
            {
                if(A[i]!=nums[(i+x)%n])
                {
                    is_match=false;
                    break;
                }
            }
            if(is_match)
            {
                return true;
            }
        }
        return false;
    }
};