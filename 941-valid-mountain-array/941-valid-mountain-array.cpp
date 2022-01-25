class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
          int i;
        for(i=0;i<arr.size()-1;i++)
        {
            if(arr[i]<arr[i+1]) continue;
            else break;
        }
        if(i==0 || i==arr.size()-1) return false;
        
        for(int j=arr.size()-1;j>i;j--)
        {
            if(arr[j]<arr[j-1]) continue;
            else return false;
        }
        return true;
    }
    
};