class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> v;
        for(int i=0;i<arr.size()-1;i++){
            int maxi=INT_MIN;
            for(int j=i+1;j<arr.size();j++){
                if(maxi<arr[j]) maxi= arr[j];
            }
            v.push_back(maxi);
        }
        v.push_back(-1);
    return v;
    }
};