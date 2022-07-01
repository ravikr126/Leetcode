class Solution {
public:
    // comparator function to sort in vector w.r.t no. of units per boxes in descending order
    static bool compare(vector<int> v1, vector<int> v2)
    {
        return v1[1]>v2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int totalUnits = 0, i = 0;
        // sort the vector in descending order w.r.t no. of units per boxes 
        sort(boxTypes.begin(), boxTypes.end(), compare);
        
        // Make sure truckSize > 0 && pointer should not exceed boxTypes.size()
        while (truckSize>0 && i<boxTypes.size()){
            
            // if current boxes is <= truckSize, that means we can take the entire current box
            if(boxTypes[i][0] <= truckSize){
                totalUnits += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            
            // if current boxes is > truckSize, we can only take a fraction from the current boxes
            else{
                
                int canTakeBoxes = truckSize;
                truckSize -= canTakeBoxes; // here truckSize = 0 
                totalUnits += canTakeBoxes * boxTypes[i][1]; 
            }
            
            // iterate the loop
            i++;
        }
    
        return totalUnits;
    }
};