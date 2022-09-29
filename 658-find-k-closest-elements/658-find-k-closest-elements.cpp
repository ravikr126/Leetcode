class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        //use pair priority queue 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
                                                                     
        //push all the element with their absolute difference
        for(auto y:arr){
            q.push({abs(x-y),y});
        }
        
        //allocate a vector which store all the value
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(q.top().second);
            //removing
            q.pop();
        }
        // sort the element in acending order
        sort(ans.begin(),ans.end());
        return ans;
    }
};