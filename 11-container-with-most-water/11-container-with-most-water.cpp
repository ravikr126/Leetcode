class Solution {
public:
    int maxArea(vector<int>& height) {
         ios_base::sync_with_stdio(false);
        int l=0, r=height.size()-1;
        int hl=0, hr=0;
        int area = 0;
        int max_area = 0;

        while (l < r) {
            hl = height[l];
            hr = height[r];
            hl < hr ? (area = (r - l) * hl, l++) : (area = (r - l) * hr, r--);
            if (area > max_area) {
                max_area = area;
            }
        }
        return max_area;
    }
};