class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();

        vector<int> candidates = {
            arr[n/4],
            arr[n/2],
            arr[3*n/4]
        };

        for (int num : candidates) {
            int first = firstOccurrence(arr, num);
            int last = lastOccurrence(arr, num);

            if (last - first + 1 > n / 4) {
                return num;
            }
        }

        return -1;
    }

private:
    int firstOccurrence(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int res = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                res = mid;
                high = mid - 1; // go left
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }

    int lastOccurrence(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int res = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                res = mid;
                low = mid + 1; // go right
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};