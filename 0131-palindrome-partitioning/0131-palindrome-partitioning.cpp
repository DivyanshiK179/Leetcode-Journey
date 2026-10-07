class Solution {
    bool isPalindrome(const string &s, int i, int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void solve(const string &s, vector<vector<string>> &output, vector<string> &temp, int i)
    {
        //base case
        if(i==s.size())
        {
            output.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();j++)
        {
            if(isPalindrome(s, i, j))
            //do partition
            {
                temp.push_back(s.substr(i, j-i+1));
                solve(s, output, temp, j+1);
                //bactrack
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> output;
        vector<string> temp;
        solve(s, output, temp, 0);
        return output;
    }
};