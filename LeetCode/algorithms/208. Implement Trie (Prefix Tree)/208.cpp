class Trie {
    class TrieNode {
        bool end = false;
        TrieNode* next[26];
    public:
        void addLetter(char c) {
            if (!next[c-'a']) next[c-'a'] = new TrieNode();
        }
        
        bool hasLetter(char c) {
            return next[c-'a'] != nullptr;
        }
        
        TrieNode* getNext(char c) { return next[c-'a']; }
        
        bool isEnd() { return end; }
        
        void putEnd() { end = true; }
    };
    
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->hasLetter(word[i])) {
                node->addLetter(word[i]);
            }
            node = node->getNext(word[i]);
        }
        node->putEnd();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->hasLetter(word[i])) {
                return false;
            }
            node = node->getNext(word[i]);
        }
        return node->isEnd();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->hasLetter(prefix[i])) {
                return false;
            }
            node = node->getNext(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */