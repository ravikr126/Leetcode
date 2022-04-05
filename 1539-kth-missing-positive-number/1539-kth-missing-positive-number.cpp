class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //  for (auto a : arr) if (a <= k) k++;
        // return k; 
        
        
        
        if(k < arr[0])
            return k;
        int low(0), high(arr.size());
        while(low < high)
        {
            int mid = low + ((high - low) >> 1);
            if(arr[mid] - mid - 1 < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low + k;
    }
};