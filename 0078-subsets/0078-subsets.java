class Solution {
    private void solve(int[] nums, List<Integer> temp, List<List<Integer>> output, int i)
    {
        if(i==nums.length)
        {
            output.add(new ArrayList<>(temp));
            return;
        }
        solve(nums,temp,output,i+1);
        temp.add(nums[i]);
        solve(nums,temp,output,i+1);  
        temp.remove(temp.size()-1);    
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> output=new ArrayList<>();
        List<Integer> temp=new ArrayList<>();
        solve(nums,temp,output,0);
        return output;
    }
}