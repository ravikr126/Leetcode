class Solution {
public:
    bool check(string q, string d){
        int count = 0;
        for(int i = 0; i < q.size(); i++){
            if(q[i] != d[i]) count++;
            if(count > 2) return false; // early exit
        }
        return true;
    }

    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string> s;

        for(int i = 0; i < q.size(); i++){
            for(int j = 0; j < d.size(); j++){
                if(check(q[i], d[j])){
                    s.push_back(q[i]);
                    break; // 🔥 prevents duplicates
                }
            }
        }
        return s;
    }
};