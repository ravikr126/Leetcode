class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
          unordered_map<int,int>st;
        int count=0;
        
		//storing in map
        for(auto &it:nums)
            st[it]++;

       // if k is 0, then which element FREQUENCY >1 can give 0
        if(k==0) 
        {
            for(auto &ko:st) if(ko.second>1) count++;
                
        }

   // if k is any other number then ,difference can currentnum+k is present then the pair can give k as a resultant
   // a-b = c
   // a= c+b
   // b =c-a
        else
        for(auto &ki:st)
        {
            if(st.count(ki.first+k)) count++;
        }
        
        return count;
    }
};