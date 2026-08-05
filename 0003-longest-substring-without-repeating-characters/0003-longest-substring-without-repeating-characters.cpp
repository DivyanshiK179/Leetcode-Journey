class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> freq(256,false);
        int j=0;
        int i=0;
        int max_win=0;
        while(j<s.size())
        {
            while(freq[s[j]])
            {
                freq[s[i]]=false;
                i++;
            }
            freq[s[j]]=true;
            int cur_win=j-i+1;
            max_win=max(max_win,cur_win);
            j++;
        }
        return max_win;
    }
};