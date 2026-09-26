#include<iostream>
#include<algorithm>
#include<map>
#include<climits>
using namespace std;
//basically topo sort and if topo sort is successfull meaning the topo.size() == V then the graph has no cycle

class Solution{
    public:
    bool isCyclic(int V,vector<int> adj[]){
        vector<int> indegree(V);
        for(int i = 0;i<V;i++){
            for(auto it: adj[i]){
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0;i<V;i++){
            if(indegree[i] == 0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] ==0 ) q.push(it);
            }
        }

        if(cnt == V) return false;
        return true;
    }
};