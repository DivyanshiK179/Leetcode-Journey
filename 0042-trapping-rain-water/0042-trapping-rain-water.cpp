class Solution {
public:
    int long trap(vector<int>& height) {
        long long n=height.size();
        vector<int> prefix_max(n);
        vector<int> suffix_max(n);
        long long water=0;
        prefix_max[0]=height[0];
        for(int i=1;i<n;i++)
        {
            prefix_max[i]=max(prefix_max[i-1],height[i]);
        }
        suffix_max[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix_max[i]=max(suffix_max[i+1],height[i]);
        }
        for(int i=0;i<n;i++)
        { 
            water+=min(prefix_max[i],suffix_max[i])-height[i];
        }
        return water;
    }
};