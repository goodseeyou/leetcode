

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int totalSize = nums1Size +nums2Size;
    int halfSizeFloor=totalSize/2;
    int isOdd = totalSize & 1;
    for(int i=0,j=0,current=NULL;;){
        if(i+j == halfSizeFloor){
            int next;
            if(i>=nums1Size){
                next = nums2[j];
            }else if(j>=nums2Size){
                next = nums1[i];
            }else if(nums1[i] <=nums2[j]){
                next = nums1[i];
            }else{
                next = nums2[j];
            }
            
            free(nums1);
            free(nums2);
            
            if(isOdd){
                return (double)next;
            } else{
                return (double)(current+next)/2.0;
            }
            
        }
        if(i>=nums1Size){
            current=nums2[j];
            j++;
            continue;
        }
        if(j>=nums2Size){
            current=nums1[i];
            i++;
            continue;
        }
        if(nums1[i]<=nums2[j]){
            current=nums1[i];
            i++;
            continue;
        }else{
            current=nums2[j];
            j++;
            continue;
        }
    }
}
