#include <string>

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum>9LL*num||sum<1) 
        {
            return "";
        }
        string ans="";
        ans.reserve(num);
        int nines=sum/9;
        int rem=sum%9;
        ans.append(nines,'9');
        if (rem>0) 
        {
            ans.push_back('0'+rem);
        }
        if((int)ans.size()<num) 
        {
            ans.append(num-ans.size(),'0');
        }
        return ans;
    }
};