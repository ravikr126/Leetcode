class Solution {
public:
    // Intuition: we can see each string as a node and we can connect them if 
    // 1. there is only one single character different
    // 2. the target node is available in `bank`
    // the problem is now to find the shortest path from the starting point to the ending point
    // so we can use BFS
    int minMutation(string start, string end, vector<string>& bank) {
        // a queue to store each gene string (node)
        queue<string> q;
        // a hash map to store if we've visited a node
        unordered_map<string, int> vis;
        // distance
        int steps = 0;
        // we start from gene string `start` as a starting point
        // push it to the queue
        q.push(start);
        // and mark it visited
        vis[start] = 1;
        // BFS
        while (!q.empty()) {
            // iterate from the back because the size of q varies
            // which would result in wrong answer if you iterate from 0
            // alternatively, you can define a new variable for q.size() before the for-loop
            // i.e. 
            // int n = q.size();
            // for (int i = 0; i < n; i++) { 
            for (int i = q.size(); i > 0; i--) {
                // get the gene string from the queue
                string s = q.front();
                q.pop();
                // if it is same as `end`, that means we found the answer
                if (s == end) return steps;
                // otherwise, given a gene string with 8-character long
                // we can replace each character with "A", "C", "G" and "T" (i.e. mutate)
                for (int j = 0; j < 8; j++) {
                    // s[j] will be modified later, 
                    // hence store the original character here
                    char oc = s[j];
                    // iterate ACGT
                    // alternatively, you can use `for (char c : "ACGT") { ... }`
                    for (int k = 0; k < 4; k++) {
                        // replace the j-th character in s with the k-th character in ACGT
                        s[j] = "ACGT"[k];
                        // we can reach the next node if the next node hasn't been visited
                        // and the next node is available in `bank`
                        if (!vis[s] && find(bank.begin(), bank.end(), s) != bank.end()) {
                            // push the next node to the queue
                            q.push(s);
                            // and mark it visited
                            vis[s] = 1;
                        }
                    }
                    // since we updated the character, we revert it back
                    s[j] = oc;
                }
            }
            // increase the step count
            steps += 1;
        }
        // not able to reach `end`, return -1 here
        return -1;
    }
};