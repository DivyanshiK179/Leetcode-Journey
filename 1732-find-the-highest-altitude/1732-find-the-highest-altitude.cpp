class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int high=0;
        int height=0;
        for(int i=0;i<gain.size();i++)
        {
            height+=gain[i];
            high=max(high,height);
        }
        return high;
    }
};