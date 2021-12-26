class Solution {
public:
    int maxArea(vector<int>& height) {
       int n = height.size();
        int i = 0;
        int j = n-1;
        int maxarea = INT_MIN;
        while(i < j){
            int hgt = min(height[i], height[j]);
            int width = j - i;
            
            int area = hgt * width;
            maxarea = max(maxarea, area);
            
            if(height[i] < height[j]) i++;
            else j--;
        }
        
        return maxarea;
    }
};