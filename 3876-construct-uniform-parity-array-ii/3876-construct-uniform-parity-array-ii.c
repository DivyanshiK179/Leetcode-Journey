#include<stdbool.h>

    bool uniformArray(int* nums1, int nums1Size) {
        int min_val=nums1[0];
        bool has_odd=false;

        for (int i=0;i<nums1Size;i++) {
            if (nums1[i]<min_val) {
                min_val=nums1[i];
            }
            if (nums1[i]%2!=0) {
                has_odd=true;
            }
        }
        return (min_val%2!=0)||!has_odd;
    }
