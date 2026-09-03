#include<iostream>
#include<algorithm>
#include<climits>
#include<math.h>
using namespace std;

class Solution{
    private:
    bool dfs(int node,vector<int>& vis,vector<int> adj[],vector<int>& pathVis){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,adj,pathVis) == true) return true;
            }
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
    public:
    bool isCyclic(int V,vector<int> adj[]){
        vector<int> vis(V,0);
        vector<int>pathVis(V,0);

        for(int i = 0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,adj,pathVis) == true) return true;
            }
        }
        return false;
    }
};