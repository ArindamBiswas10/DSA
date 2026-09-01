#include<iostream>
#include<climits>
#include<algorithm>
#include<math.h>
using namespace std;

class Solution{
    private:
    void bfs(int row,int col, vector<vector<char>>& grid,vector<vector<int>>& vis){
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //traverse in neighbors and mark them if 1
            for(int delRow = -1;delRow<=1;delRow++){
                for(int delCol = -1;delCol<=1;delCol++){
                    int nRow = row + delRow;
                    int nCol = col + delCol;
                    if(nRow<n && nRow>=0 && nCol<m && nCol>=0 && !vis[nRow][nCol] && grid[nRow][nCol] == '1'){
                        vis[nRow][nCol] = 1;
                        q.push({nRow,nCol});
                    } 
                }
            }
        }  
    }

    public:
    int numIslands(vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int row = 0;row<n;row++){
            for(int col = 0;col<m;col++){
                if(!vis[row][col]){
                    cnt++;
                    bfs(row,col,grid,vis);
                }
            }
        }
        return cnt;
    }

};

//T.C-> O(N) + O(V + 2E)