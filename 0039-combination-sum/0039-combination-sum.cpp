class Solution {
    void solve(vector<int> candidates, int target, vector<vector<int>> &answer, vector<int> temp, int i)
    {
        if(target==0)
        {
            answer.push_back(temp);
            return;
        }
        if(i==candidates.size())
        {
            return;
        }
        if(candidates[i]<=target)
        {
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],answer,temp,i);
            temp.pop_back();
        }
        solve(candidates,target,answer,temp,i+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> temp;
        solve(candidates,target,answer,temp,0);
        return answer;
    }
};