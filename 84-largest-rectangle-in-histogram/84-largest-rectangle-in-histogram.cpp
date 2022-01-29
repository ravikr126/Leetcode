class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        int n = height.size(), area = 0;
        stack<int> indexes;
        for (int i = 0; i < n; i++) {
            while (!indexes.empty() && height[indexes.top()] > height[i]) {
                int h = height[indexes.top()]; indexes.pop();
                int l = indexes.empty() ? -1 : indexes.top();
                area = max(area, h * (i - l - 1));
            }
            indexes.push(i);
        }
        return area; 
    }
};