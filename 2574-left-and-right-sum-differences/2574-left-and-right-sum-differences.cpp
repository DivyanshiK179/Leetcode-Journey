class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> leftsum(n,0);
        vector<int> rightsum(n,0);
        vector<int> res(n);
        for(int i=1;i<n;i++)
        {
            leftsum[i]=leftsum[i-1]+nums[i-1];
        }
        for(int j=n-2;j>=0;j--)
        {
            rightsum[j]=rightsum[j+1]+nums[j+1];
        }
        for(int i=0;i<n;i++)
        {
            res[i]=abs(leftsum[i]-rightsum[i]);
        }
        return res;
    }
};