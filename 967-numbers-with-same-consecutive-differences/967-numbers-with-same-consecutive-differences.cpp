class Solution {
public:
    vector<int>ans;
   void helper(int n, int k,int len,int val){
        if(len==n){
            ans.push_back(val);
            return;
        }
        int rem=val%10;
        if(rem+k<=9){
            helper( n,  k, len+1, val*10+rem+k);
        }
         if(k!=0 && (rem-k)>=0){
             helper( n,  k, len+1, val*10+(rem-k));
        }
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++){
            helper( n,  k, 1, i); 
        }
        
        return ans;
       
    }
};
