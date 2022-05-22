int* mergeSort(int* nums1, int nums1Size, int* nums2, int nums2Size);

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int* merges = mergeSort(nums1,nums1Size,nums2,nums2Size);
    double ans;
    if((nums1Size+nums2Size)&1){
        // odd
        ans= (double) merges[(nums1Size+nums2Size)/2];
    } else{
        // even
        ans= (double) (merges[(nums1Size+nums2Size)/2-1]+ merges[(nums1Size+nums2Size)/2])/2.0;
    }
    free(merges);
    return ans;
}

int* mergeSort(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int* merges = malloc(sizeof(int)*(nums1Size+nums2Size));
    for(int i=0,j=0;i<nums1Size||j<nums2Size;){
        if(i>=nums1Size){
            merges[i+j] = nums2[j];
            j++;
            continue;
        }
        if(j>=nums2Size){
            merges[i+j] = nums1[i];
            i++;
            continue;
        }
        if(nums2[j]<nums1[i]){
            merges[i+j] = nums2[j];
            j++;
            continue;
        } else {
            merges[i+j] = nums1[i];
            i++;
            continue;
        }
        
    }
    free(nums1);
    free(nums2);
    return merges;
}

