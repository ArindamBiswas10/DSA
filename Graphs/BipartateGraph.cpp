#include<iostream>
#include<algorithm>
#include<climits>
#include<math.h>
using namespace std;

class Solution{
    private:
    bool check(int start,int V,vector<vector<int>>&adjLs,vector<int>& color){
        queue<int>q;
        q.push(start);
        color[start] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adjLs[node]){
                if(color[it] != -1){
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
  bool isBipartate(int V, vector<vector<int>>&adjLs){
    vector<int>color(V);
    for(int i = 0;i<V;i++) color[i] = -1;

    for(int i = 0;i<V;i++){
        if(color[i] == -1){
            if(check(i,V,adjLs,color));
        }
    }
  }  
};