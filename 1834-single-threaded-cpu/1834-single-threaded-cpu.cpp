typedef vector<int> pi;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        int len = tasks.size();
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        for(int i=0;i<len;i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        int count = 0;
        int maxEnqueueTime = 0;
        while(ans.size()<len){
            if(count<len && pq.empty()){
                maxEnqueueTime = max(maxEnqueueTime, tasks[count][0]);
            }
            while(count<len && maxEnqueueTime>=tasks[count][0]){
                pq.push({tasks[count][1],tasks[count][2]});
                count++;
            }
            auto temp = pq.top();
            pq.pop();
            maxEnqueueTime = min(1000000000,temp[0]+maxEnqueueTime);
            ans.push_back(temp[1]);

        }
        
        return ans;
    }
   
};