int trap(int* height, int heightSize) {
        int n=heightSize;
        int* prefix_max=(int*)malloc(n*sizeof(int));
        int* suffix_max=(int*)malloc(n*sizeof(int));
        int water=0;
        prefix_max[0]=height[0];
        for(int i=1;i<n;i++)
        {
            prefix_max[i]=MAX(prefix_max[i-1],height[i]);
        }
        suffix_max[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix_max[i]=MAX(suffix_max[i+1],height[i]);
        }
        for(int i=0;i<n;i++)
        { 
            water+=MIN(prefix_max[i],suffix_max[i])-height[i];
        }
        return water;
}