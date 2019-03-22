struct TrieNode {
    bool isFinal;
    vector<TrieNode*> next;
    int size;
    
    TrieNode(): isFinal(false), size(0) { next.assign(26, NULL); }
};

struct Trie {
    TrieNode* root;
    
    Trie() { root = new TrieNode(); }
    ~Trie();
    
    void insert(string &);
    string prefix(string &);

    void clear(TrieNode*);
};

void Trie::insert(string &s) {
    TrieNode* node = root;
    
    for (char c : s) {
        if (node->next[c-'a'] == NULL)
            node->next[c-'a'] = new TrieNode();

        node->size++;
        node = node->next[c-'a'];
    }
    node->isFinal = true;
}

string Trie::prefix(string &s) {
    TrieNode* node = root;
    string pre = "";
    
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (node->size == 1) break;
        
        node = node->next[c-'a'];
        pre.push_back(c);
    }
    
    return pre;
}

Trie::~Trie() { clear(root); }

void Trie::clear(TrieNode* node) {
    if (node == NULL) return;
    
    for (TrieNode* n : node->next) clear(n);
    
    delete node;
}


vector<string> Solution::prefix(vector<string> &A) {
    Trie trie;
    
    for (string s : A) trie.insert(s);
    
    vector<string> ans;
    for (string s : A) ans.push_back(trie.prefix(s));
    
    return ans;
}
