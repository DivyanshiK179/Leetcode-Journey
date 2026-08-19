class Solution {
    private boolean ispossible(int[] position,int mid,int m){
            int ball=1;
            int pos=position[0];
            for(int i=1;i<position.length;i++)
            {
                if(position[i]-pos>=mid)
                {
                    ball++;
                    pos=position[i];
                }
                if(ball==m)
                {
                    return true;
                }
            }
            return false;
        }

    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);
        int ans=-1;
        int s=1;
        int n=position.length;
        int e=position[n-1]-position[0];
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(ispossible(position,mid,m))
            {
                ans=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return ans;
    }
}