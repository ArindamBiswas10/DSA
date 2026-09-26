//Kahn's algo
#include<iostream>
#include<algorithm>
#include<climits>
#include<math.h>
using namespace std;

class Solution{
    public:
    vector<int> topoSort(vector<vector<int>>& edges,int V){
        vector<vector<int>> adjLs(V);
        for(auto& e: edges){
            adjLs[e[0]].push_back(e[1]);
        }
        queue<int> q;
        vector<int> indegree(V);
        for(int i = 0;i<V;i++){
            for(auto it : adjLs[i]){
                indegree[it]++;
            }
        }

        for(int i = 0;i<V;i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adjLs[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }

        }
        return topo;
    }
};