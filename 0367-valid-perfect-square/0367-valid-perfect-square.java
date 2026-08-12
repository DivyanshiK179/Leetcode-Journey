class Solution {
    public boolean isPerfectSquare(int num) {
        long s=1;
        long e=num;
        while(s<=e)
        {
            long m=(s+e)/2;
            long mid=m*m;
            if(mid==num)
            {
                return true;
            }
            else if(mid<num)
            {
                s=m+1;
            }
            else
            {
                e=m-1;
            }
        }
        return false;
    }
}