// Example program
#include <bits/stdc++.h>
#include <time.h> 
using namespace std;

class TrieNode {
public:
    bool isFinal;
    vector<TrieNode *> next;
    
    TrieNode(): isFinal(false) { next.assign(26, NULL); }

    void putChar(char c) {
        if (next[c-'a'] == NULL)
            next[c-'a'] = new TrieNode();
    }
    
    TrieNode* nextNode(char c) {
        return next[c-'a'];
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() { root = new TrieNode(); }
    
    void insert(string &s) {
        TrieNode *aux = root;
        
        for (char c : s) {
            aux->putChar(c);
            aux = aux->nextNode(c);
        }
        aux->isFinal = true;
    }
    
    bool contains(string &s) {
        TrieNode *node = root;
        
        for (char c : s) {
            if (node == NULL or node->isFinal) return false;
            node = node->nextNode(c);
        }
        return node->isFinal;
    }
};

vector<string> split(string &s, char sep) {
    vector<string> ans;
    string cur = "";
    
    for (char c : s)
        if (c == sep and cur != "") {
            ans.push_back(cur);
            cur = "";
        } else cur.push_back(c);
    
    if (cur != "") ans.push_back(cur);
    return ans;
} 

int goodnessValue(string s, Trie &tr) {
    vector<string> rev = split(s,'_');
    int val;
    for (string ss : rev)
        if (tr.contains(ss))
            val++;
    return val;
} 

vector<int> solve(string A, vector<string> &B) {
    vector<string> goods = split(A,'_');
    
    
    printf("Inserindo na Trie\n");
    Trie tr;
    for (string s : goods) 
        tr.insert(s);

    string g = "cooo";
    cout << "cool esta na trie? " << (tr.contains(g) ? "SIM" : "NAO") << endl; 
    
    printf("Calculando os goodnessValues\n");
    vector<pair<int,int>> aux;
    for (int i = 0; i < B.size(); i++)
        aux.push_back({goodnessValue(B[i], tr),i});
    
    printf("Ordenando\n");
    sort(aux.begin(), aux.end());
    
    printf("Construindo resposta\n");
    vector<int> ans;
    for (pair<int, int> p : aux) 
        ans.push_back(p.second);
    
    return ans;
}

void readInput(string &A, vector<string> &B);

int main() {
    // string A; vector<string> B;
    // readInput(A,B);

    // vector<int> ans = solve(A,B);

    // for (int x : ans)
    //     cout << x << " ";
    // cout << endl;

    // return 0;

    
}

void readInput(string &A, vector<string> &B) {
    cin >> A;
    int n; cin >> n;

    while (n--) {
        string aux; cin >> aux;
        B.push_back(aux);
    }
}
