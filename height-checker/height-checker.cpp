class Solution {
public:
    int heightChecker(vector<int>& heights) {
         int count= 0;
        vector<int>sorted;
        int temp = 0;
        for(int i = 0; i < heights.size(); i++){
            sorted.push_back(heights[i]);
        }
        sort(sorted.begin(),sorted.end());
        for(int i = 0; i < heights.size(); i++){
            if(heights[i] != sorted[i]){
                count++;
            }
        }
        return count;
    }
};