class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int sum = 0;
        
        int n = neededTime.size();
        
        for(int i=0;i<n;i++)
        {
            sum+=neededTime[i];
        }
        
        int max_sum = 0;
        
        for(int i=0;i<n;i++)
        {
            int max_val = neededTime[i];
            
            while(i<n-1 && colors[i+1]==colors[i])
            {
                max_val = max(max_val,neededTime[i+1]);
                i++;
            }
            //cout << max_val << endl;
            //cout << "i : " << i << endl;
            max_sum+=max_val;
            
            
        }
        
        return sum - max_sum;
    }
};