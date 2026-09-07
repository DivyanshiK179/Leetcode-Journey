class Solution {
public:
    int distinctSubseqII(string s) 
    {
        long long mod=1e9+7;
        vector<long long> ends_with(26,0);
        long long total=0;
        for (char c:s) 
        {
            int idx=c-'a';
            long long new_ends_with=(total+1)%mod;
            total=(total+new_ends_with-ends_with[idx]+mod)%mod;
            ends_with[idx]=new_ends_with;
        }
        return total;
    }
};