class Solution {
public:
    int maxProfit(vector<int>& v) {
        int min = v[0],max=-1;
        int profit=0;
        for(int i=1;i<v.size();i++)
        {
            if(v[i]<min){
                min = v[i];
                max = 0;
            }
            if(v[i]>max)
                max = v[i];
            if(max-min>profit)
                profit = max -min;
        }
        return profit;
    }
};