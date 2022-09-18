class Solution {
public:
    int trap(vector<int>& height) {
          int maxHeight = -1;
        int blocks = 0;
        long long scanFromLeft = 0;
        for (int i = 0; i < height.size(); i++) {
            maxHeight = max(maxHeight, height[i]);
            scanFromLeft += maxHeight;
            blocks += height[i];
        }
        
        maxHeight = -1;        
        long long scanFromRight = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            maxHeight = max(maxHeight, height[i]);
            scanFromRight += maxHeight;
        }
        
        return scanFromLeft + scanFromRight - maxHeight * height.size() - blocks;
    }
};