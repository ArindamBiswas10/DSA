#include<iostream>
#include<algorithm>
#include<climits>
#include<math.h>
using namespace std;

class Solution{
    private:
    bool detect(int start,int V,vector<vector<int>>& adjLs,vector<int>& color){
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: adjLs[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    public:
    bool isBipartite(int V,vector<vector<int>>& edges){
        vector<vector<int>>adjLs(V);
        for(auto& e:edges){
            adjLs[e[0]].push_back(e[1]);
            adjLs[e[1]].push_back(e[0]);
        }

        vector<int>color(V,-1);
        for(int i = 0;i<V;i++){
            if(color[i] == -1){
                if(detect(i,V,adjLs,color) == false) return false;
            }
        }

        return true;
    }
};