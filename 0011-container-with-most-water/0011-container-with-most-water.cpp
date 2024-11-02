class Solution {
public:
    int maxArea(vector<int>& height) {
        int siz= height.size();
        int area=0;
        int maxi=0;
        int i=0;
        int j=siz-1;
        while(i<=j){
            if(height[i]>height[j]){
                maxi= height[j]* (j-i);
                j--;

            }else{
                 maxi= height[i]* (j-i);
                 i++;
            }
            area= max(area,maxi);
        }
        return area;
    }
};