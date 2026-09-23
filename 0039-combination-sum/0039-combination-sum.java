class Solution {
    private void solve(int[] candidates, int target, List<List<Integer>> answer, List<Integer> temp, int i)
    {
        if(target==0)
        {
            answer.add(new ArrayList<>(temp));
            return;
        }
        if(i==candidates.length)
        {
            return;
        }
        if(candidates[i]<=target)
        {
            temp.add(candidates[i]);
            solve(candidates,target-candidates[i],answer,temp,i);
            temp.remove(temp.size()-1);
        }
        solve(candidates,target,answer,temp,i+1);
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> answer= new ArrayList();
        List<Integer> temp=new ArrayList<>();
        solve(candidates,target,answer,temp,0);
        return answer;
    }
}