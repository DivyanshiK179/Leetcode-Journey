class Solution {
    void solve(int k, int target, vector<vector<int>> &answer, vector<int> temp, int i)
    {
        if(target==0 && k==0)
        {
            answer.push_back(temp);
            return;
        }
        if(i==10)
        {
            return;
        }
        if(i<=target)
        {
            temp.push_back(i);
            solve(k-1,target-i,answer,temp,i+1);
            temp.pop_back();
        }
        solve(k,target,answer,temp,i+1);
    }
public:
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> answer;
        vector<int> temp;
        solve(k,target,answer,temp,1);
        return answer;
    }
};