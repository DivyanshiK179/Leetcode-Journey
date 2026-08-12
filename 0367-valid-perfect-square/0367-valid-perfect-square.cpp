class Solution {
public:
    bool isPerfectSquare(int num) {
        long long s=1;
        long long e=num;
        while(s<=e)
        {
            long long m=(s+e)/2;
            long long mid=m*m;
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
};