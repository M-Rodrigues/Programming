// link: https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

// SCC

{
#include<bits/stdc++.h>
 
using namespace std;
 #define MAX 10001
int kosaraju(vector<int> v[100001],int ,int );
int main()
{ 
   int t;
   cin>>t;
  while(t--)
   {   vector<int> v[100001];
        int a,b ;
   	cin>>a>>b;
       for(int i=0;i<b;i++)
           {  int m,n;
               cin>>m>>n;
               v[m].push_back(n);
           }
      
         
         int ans=kosaraju(v,a,b); 
         cout<<ans<<endl;
         for(int i=0;i<=a+1;i++)
        {    v[i].clear();   
         }
           
   }
return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The function takes an adjacency list representation of the graph g
    and two integers N and M as specified in the problem statement
    You are required to complete this method. */


void dfs(int x, vector<int> *v, vector<bool> &vis, stack<int> &st);
void dfst(int x, vector<int> *vt, vector<bool> &vis);
vector<int>* transpose(vector<int> *v, int N,vector<int> *vt);

int kosaraju(vector<int> v[100001], int N, int M)
{
    // Your code here
    vector<bool> visited(N+1, false);
    stack<int> st;
    
    // dfs normal
    for (int i = 1; i <= N; i++)
        if (!visited[i])
            dfs(i, v, visited, st);
    
    // transpose graph
    vector<int> vt[10001];
    transpose(v, N, vt);
    
    // dfs voltando
    int ans = 0;
    while (!st.empty()) {
        int i = st.top();
        st.pop();
        
        if (visited[i]) {
            dfst(i, vt, visited);
            ans++;
        }
    }
    
    return ans;
}

void dfs(int x, vector<int> *v, vector<bool> &vis, stack<int> &st) {
    if (vis[x]) return;
    vis[x] = true;
    for (int u : v[x])
        dfs(u,v,vis,st);
    st.push(x);
}


void dfst(int x, vector<int> *vt, vector<bool> &vis) {
    if (!vis[x]) return;
    vis[x] = false;
    for (int u : vt[x])
        dfst(u,vt,vis);
}

vector<int>* transpose(vector<int> *v, int N,vector<int> *vt) {
    for (int i = 1; i <= N; i++) {
        for (int j : v[i]) {
            vt[j].push_back(i);
        }
    }
}
