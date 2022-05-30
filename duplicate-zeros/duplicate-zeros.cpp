class Solution {
public:
   
    void duplicateZeros(vector<int>& arr) {
        int numberOfZeros = 0;
        
        for (int each: arr){
            if (each == 0)
                numberOfZeros += 1;
        }
        
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] == 0 && i < arr.size()-1){
                shift(arr, i+1);
                arr[i+1] = 0;
                i += 1;
            }
        }
        
    }
    
    void shift(vector<int>& arr, int index){
        int temp;
        if (index < arr.size()){
            int i = arr.size()-1;
            
            while (i > index){
                arr[i] = arr[i-1];
                i -= 1;
            }
            
        }
    }

};