class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//       stack<int>s;
//         int j=0;
//         for(int i=0;i<pushed.size();i++)
//         {
//              s.push(pushed[i]);
//             if(s.top()==popped[j])
//             {
//                 s.pop();
//                 j++;
//             }
           
//         }
//         if(s.size()>0)
//             return false;
//         return true;
          int i = 0; // Intialise one pointer pointing on pushed array
        int j = 0; // Intialise one pointer pointing on popped array
        
        for(auto val : pushed){
            pushed[i++] = val; // using pushed as the stack.
            while(i > 0 && pushed[i - 1] == popped[j]){ // pushed[i - 1] values equal to popped[j];
                i--; // decrement i
                j++; // increment j
            }
        }
        return i == 0; 
    }
};