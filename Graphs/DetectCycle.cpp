#include<iostream>
#include<algorithm>
#include<climits>
#include<math.h>
using namespace std;

class Solution{
    private:
    bool detect(int src,vector<vector<int>>& adjLs,vector<int>& vis){
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src,-1});

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto adjacentNode: adjLs[node]){
                if(!vis[adjacentNode]){
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode,node});
                }
                else if(parent != adjacentNode){
                    return true;
                }
            }
        }
        return false;

    }

    public:
    bool isCycle(vector<vector<int>>&edges,int V){
        vector<vector<int>> adjLs(V);
        for(auto& e:edges){
            adjLs[e[0]].push_back(e[1]);
            adjLs[e[1]].push_back(e[0]);
        }
        vector<int>vis(V,0);
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adjLs,vis) == true) return true;
            }
        }
        return false;
    }    
};