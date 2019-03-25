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

void readInput(string &A, vector<int> &B);

vector<int> dp;

int solve(int k, vector<int> &A) {
    if (k >= A.size()) return INT_MAX - 1;
    if (dp[k] != -1) return dp[k];
    
    printf("(%d) dp[%d] = %d\n",A[k],k,dp[k]);
    for (int i = 1; i <= A[k]; i++) {
        int aux = solve(i+k,A);
        if (aux == -1) aux = INT_MAX-1;

        if (i == 1) {
            dp[k] = aux + 1; continue;
        } else {
            dp[k] = min(dp[k], aux+1);
        }
    }
    if (dp[k] == INT_MAX) dp[k] == -1;    
    return dp[k];
}

int jump(vector<int> &A) {
    dp.assign(A.size(), -1);
    dp[A.size()-1] = 0;
    return solve(0, A);
}


int main() {
    string A; vector<int> B;
    readInput(A,B);

    jump(B);

    for (int k = 0; k < dp.size(); k++) 
        printf("(%d) dp[%d] = %d\n",B[k],k,dp[k]);

}

void readInput(string &A, vector<int> &B) {
    int n; cin >> n;

    while (n--) {
        int aux; cin >> aux;
        B.push_back(aux);
    }
}
