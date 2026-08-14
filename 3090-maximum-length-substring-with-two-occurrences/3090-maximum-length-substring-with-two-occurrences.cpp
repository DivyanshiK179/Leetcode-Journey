class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0;
        int j=0;
        vector<int> freq(256,0);
        vector<char> str;
        int ans=INT_MIN;
        int len=s.size();
        int sum=0;
        for(int i=0;i<len;i++)
        {
            str.push_back(s[i]);
        }
        while(j<s.size())
        {
            sum+=str[j];
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