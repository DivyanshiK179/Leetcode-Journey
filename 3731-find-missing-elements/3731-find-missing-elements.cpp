class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> res;
        int minn=*min_element(nums.begin(),nums.end());
        int maxx=*max_element(nums.begin(),nums.end());
        for(int i=minn;i<maxx;i++)
        {
            if(find(nums.begin(),nums.end(),i)!=nums.end())
            {
                continue;
            }
            res.push_back(i);
        }
        return res;
    }
};