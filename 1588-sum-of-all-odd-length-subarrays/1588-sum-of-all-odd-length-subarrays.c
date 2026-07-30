int sumOddLengthSubarrays(int* arr, int arrSize) {
    int ans=0;
        for(int i=0;i<arrSize;i++)
        {
            int sum=0;
            for(int j=i;j<arrSize;j++)
            {
                sum+=arr[j];
                if((j-i+1)%2!=0)
                {
                    ans+=sum;
                }
            }
        }
        return ans;
}