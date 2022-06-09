class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i =0,j = numbers.size()-1;
        
        while(i<j){
            int k = numbers[i]+numbers[j];
            
            if(k==target){
               vector<int> ans{i+1,j+1}; 
              return ans;
            }
            
            if(k<target){
                
                i++;
                continue;
            }
            
            if(k>target){
                j--;
                continue;
            }
        }
        
        return numbers;    
    }
};