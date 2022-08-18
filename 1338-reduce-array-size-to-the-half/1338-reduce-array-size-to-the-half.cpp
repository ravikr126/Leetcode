class Solution {
public:
    int minSetSize(vector<int>& arr) {
         unordered_map<int,int>h;
        for(int i = 0; i < arr.size(); i++) h[arr[i]]++;
        priority_queue<int> pq;
        for(auto it: h) pq.push(it.second);
        int ans = 0, minus = 0;
        while(!pq.empty())
        {
            ans++;
            minus += pq.top();
            pq.pop();
            if(minus >= (arr.size()/2)) break;
        }
        return ans;
    }
};