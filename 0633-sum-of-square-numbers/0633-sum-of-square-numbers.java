class Solution {
    public boolean judgeSquareSum(int c) {
        long left=0;
        long right=(long)Math.sqrt(c);
        while(left<=right)
        {
            long cur_sum=left*left+right*right;
            if(cur_sum==c)
            {
                return true;
            }
            else if(cur_sum<c)
            {
                left+=1;
            }
            else
            {
                right-=1;
            }
        }
        return false;
    }
}