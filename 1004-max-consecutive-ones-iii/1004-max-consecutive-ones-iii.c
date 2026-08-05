int longestOnes(int* nums, int numsSize, int k) {
        int i=0;
        int j=0;
        int max_win=-1;
        while(j<numsSize)
        {
            if(nums[j]==0)
            {
                k--;
            }
            while(k==-1)
            {
                if(nums[i]==0)
                {
                    k++;
                }
                i++;
            }
            int curr_win=j-i+1;
            max_win=MAX(max_win,curr_win);
            j++;
        }
        return max_win;
}