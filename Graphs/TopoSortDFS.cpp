#include<iostream>
#include<algorithm>
#include<math.h>
#include<climits>
using namespace std;

class Solution{
    private:
    void dfs(int node,vector<vector<int>>& adjLs,vector<int>& vis,stack<int>& st){
        vis[node] = 1;
        for(auto it: adjLs[node]){
            if(!vis[it]) dfs(it,adjLs,vis,st);
        }
        st.push(node);
    }
    public:
    vector<int> topoSort(vector<vector<int>>& edges, int V){
        vector<vector<int>> adjLs(V);
        for(auto& e:edges){
            adjLs[e[0]].push_back(e[1]);
        }
        vector<int> vis(V,0);
        stack<int> st;
        for(int i = 0;i<V;i++){
            if(!vis[i]) dfs(i,adjLs,vis,st);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
    }
};