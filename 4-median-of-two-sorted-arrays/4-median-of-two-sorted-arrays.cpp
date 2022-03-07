class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         int array_length_sum = nums1.size() + nums2.size();
        int median_index0 = array_length_sum / 2;
        int median_index1 = median_index0;
        if (array_length_sum % 2 == 0)
        {
            median_index0--;
        }
        
        int64_t sum = 0;
        int nums1_index = 0;
        int nums2_index = 0;
        for (int i = 0; i <= median_index1; i++)
        {
            int value;
            if (nums2_index >= nums2.size() || (nums1_index < nums1.size() && nums1[nums1_index] <= nums2[nums2_index]))
            {
                value = nums1[nums1_index++];
            }
            else
            {
                value = nums2[nums2_index++];
            }
            
            if (i == median_index0)
            {
                sum += value;
            }
            if (i == median_index1)
            {
                sum += value;
            }
        }
        
        return static_cast<double>(sum) / 2.0;
    
    }
};