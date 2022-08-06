class Solution {
public:
   struct node {
        bool a;
        node* n[26];
    };
    
    static void addWord(node* p, const string& word) {
        for (char c : word) {
            if (nullptr == p->n[c - 'a'])
                p->n[c - 'a'] = new node({false, {0}});
            p = p->n[c - 'a'];
        }
        p->a = true;
    }
    
    static void floodFill(vector<vector<char>>& board, int r, int c,
                          node* root, vector<string>& ret, string& word) {
        if(r < 0 || r >= board.size())
            return ;
        if(c < 0 || c >= board[0].size())
            return ;
        auto tmp = board[r][c];
        if ('\0' == tmp)
            return;
        auto p = root->n[tmp - 'a'];
        if(nullptr == p)
            return ;
        board[r][c] = '\0';
        word.push_back(tmp);
        floodFill(board, r + 1, c, p, ret, word);
        floodFill(board, r - 1, c, p, ret, word);
        floodFill(board, r, c + 1, p, ret, word);
        floodFill(board, r, c - 1, p, ret, word);
        board[r][c] = tmp;
        if (p->a)
            ret.push_back(word);
        p->a = false;
        word.pop_back();
        for (int i = 0; i < 26; ++i)
            if (nullptr != p->n[i])
                return;
        delete p;
        root->n[tmp - 'a'] = nullptr;
    }
    
    static void freeMem(node* p) {
        if (nullptr == p)
            return;
        for (int i = 0; i < 26; ++i)
            freeMem(p->n[i]);
        delete p;
    }
public:
    static vector<string> findWords(vector<vector<char>>& board, const vector<string>& words) {
        vector<string> ret;
        node* root = new node();
        string word;
        for (auto& word : words)
            addWord(root, word);
        for (int i = 0; i < size(board); ++i)
            for (int j = 0; j < size(board.front()); ++j)
                floodFill(board, i, j, root, ret, word);
        freeMem(root);
        return ret;
    }

};