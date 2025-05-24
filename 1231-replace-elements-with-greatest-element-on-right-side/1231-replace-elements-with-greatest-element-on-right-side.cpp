class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
       int n=arr.size();
       int val=arr[n-1];
       arr[n-1]=-1;
        
       for(int i=n-2; i>=0; i--){
          int x=arr[i];
           arr[i]=val;
          val=max(val, x);
         
       }
       return arr;
    }
};