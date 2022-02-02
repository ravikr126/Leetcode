class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         int len_1 = nums1.size(), len_2 = nums2.size();
        int idx_1 = 0, idx_2 = 0, idx_m = 0;

        int len_m = len_1 + len_2;
        vector<int> merged(len_m);
		
		//Sort and merge both the arrays untill one of them is exausted.
        while (idx_1 < len_1 && idx_2 < len_2)
        {
            if (nums1[idx_1] <= nums2[idx_2])
            {
                merged[idx_m] = nums1[idx_1];
                idx_1++;
            }
            else
            {
                merged[idx_m] = nums2[idx_2];
                idx_2++;
            }
            idx_m++;
        }

		//Copy remaining elements of array 1, if any
        while (idx_1 < len_1)
        {
            merged[idx_m++] = nums1[idx_1++];
        }
		
		//Copy remaining elements of array 2, if any
        while (idx_2 < len_2)
        {
            merged[idx_m++] = nums2[idx_2++];
        }

        int mid = len_m / 2;
		
		//Get median of merged array
        if (len_m % 2 == 0)
        {
            return (merged[mid - 1] + merged[mid]) / 2.0;
        }
        else
        {
            return (merged[mid]);
        }
    
    }
};