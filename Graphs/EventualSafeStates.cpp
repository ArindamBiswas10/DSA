//BFS approach
#include<iostream>
#include<algorithm>
#include<math.h>
#include<climits>
using namespace std;

class Solution{
    public:
    vector<int> EventualSafeStates(vector<vector<int>>& graph){
        int V = graph.size();
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V);
        for(int i = 0;i<V;i++){
            for(auto it:graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int>q;
        for(int i = 0;i<V;i++){
            if(indegree[i] == 0) q.push(i);
        }       
        vector<int> safeNodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for(auto it : adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};