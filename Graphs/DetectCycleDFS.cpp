#include<iostream>
#include<algorithm>
#include<climits>
#include<math.h>
using namespace std;

class Solution{
    private:
    bool dfs(int node,int parent,vector<int> adjLs[],vector<int>& vis){
        vis[node] = 1;
        for(auto adjacentNode : adjLs[node]){
            if(!vis[adjacentNode]){
                if(dfs(adjacentNode,node,adjLs,vis) == true) return true;
            }
            else if(adjacentNode != parent) return true;
        }
        return false;    
    }

public:
bool isCycle(vector<int> adjLs[],int V){
    vector<int> vis(V,0);
    for(int i = 0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,-1,adjLs,vis) == true) return true;
        }
    }
    return false;
}
};