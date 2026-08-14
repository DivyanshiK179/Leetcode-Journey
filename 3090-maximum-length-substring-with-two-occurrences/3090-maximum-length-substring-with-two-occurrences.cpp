class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0;
        int j=0;
        vector<int> freq(256,0);
        vector<char> str;
        int ans=INT_MIN;
        int len=s.size();
        for(int i=0;i<len;i++)
        {
            str.push_back(s[i]);
        }
        while(j<len)
        {
            freq[str[j]]++;
            while(freq[str[j]]>2)
            {
                freq[str[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};