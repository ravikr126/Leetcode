class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         sort(intervals.begin(), intervals.end());
        int n = intervals.size();
		
		vector<int> temp = intervals[0];
        vector<vector<int>> ans;
        int i = 1;
        
		while(i<n){
            if(intervals[i][0]<=temp[1]){
                temp[1] = max(temp[1], intervals[i][1]);
                i++;
            }
            else{
                ans.push_back(temp);
                temp = intervals[i];
                i++;
            }
        }
		
        ans.push_back(temp);
		
        return ans;
    }
};