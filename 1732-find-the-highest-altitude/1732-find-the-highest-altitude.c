int largestAltitude(int* gain, int gainSize) {
        int high=0;
        int height=0;
        for(int i=0;i<gainSize;i++)
        {
            height+=gain[i];
            high=MAX(high,height);
        }
        return high;
}