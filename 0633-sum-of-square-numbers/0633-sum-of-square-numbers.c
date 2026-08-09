bool judgeSquareSum(int c) {
        long long left=0;
        long long right=sqrt(c);
        while(left<=right)
        {
            long long cur_sum=left*left+right*right;
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