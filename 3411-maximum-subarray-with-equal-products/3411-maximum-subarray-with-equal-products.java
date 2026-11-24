class Solution {
    private int gcd(int a, int b)
    {
        while(b!=0)
        {
            int temp=a%b;
            a=b;
            b=temp;
        }
        return a;
    }

    private int lcm(int a, int b)
    {
        if(a==0 || b==0)
        {
            return 0;
        }
        return (a/gcd(a, b))*b;
    }

    public int maxLength(int[] nums) {
        int n=nums.length;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            long prod=1;
            int g=0;
            int l=1;
            for(int j=i;j<n;j++)
            {
                prod*=nums[j];
                l=lcm(nums[j],l);
                g=gcd(nums[j],g);
                if(prod==1L*l*g)
                {
                    ans=Math.max(ans,j-i+1);
                }
                if(prod>25200)
                {
                    break;
                }
            }
        }
        return ans;
    }
}