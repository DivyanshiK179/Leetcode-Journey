int peakIndexInMountainArray(int* arr, int arrSize) {
        long long s=0;
        long long e=arrSize-1;
        while(s<=e)
        {
            long long mid=(s+e)/2;
            if(arr[mid]<arr[mid+1])
            {
                s=mid+1;
            }
            else if(arr[mid-1]>arr[mid])
            {
                e=mid-1;
            }
            else if(arr[mid]>arr[mid+1])
            {
                return mid;
            }
        }
        return -1;
}