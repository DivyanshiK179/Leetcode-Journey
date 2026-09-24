class Solution {
    void solve(vector<int>& candidates, int target, vector<vector<int>> &answer, vector<int> temp, int i)
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
        if(target>=candidates[i])
        {
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],answer,temp,i+1);
            temp.pop_back();
            while(i+1<candidates.size() && candidates[i]==candidates[i+1])
            {
                i++;
            }
        }
        solve(candidates,target,answer,temp,i+1);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> answer;
        vector<int> temp;
        solve(candidates,target,answer,temp,0);
        return answer;
    }
};