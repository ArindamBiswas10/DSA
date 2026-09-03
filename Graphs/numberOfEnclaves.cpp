#include<iostream>
#include<algorithm>
#include<math.h>
#include<climits>
using namespace std;

class Solution{
    int numberOfEnclaves(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(grid[i][j] == 1){
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
        }

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,+1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0;i<4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && vis[nRow][nCol] != 1 && grid[nRow][nCol] == 1){
                    vis[nRow][nCol] = 1;
                    q.push({nRow,nCol});
                }
            }
        }

        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] && vis[i][j] == 0) cnt++; 
            }
        }

        return cnt;
    }
};

//dfs version
class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,int delRow[],int delCol[]){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && vis[nRow][nCol] == 0 && grid[nRow][nCol] == 1){
                dfs(nRow,nCol,grid,vis,delRow,delCol);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        for(int j = 0;j<m;j++){
            if(!vis[0][j] && grid[0][j] == 1){
                dfs(0,j,grid,vis,delRow,delCol);
            }
            if(!vis[n-1][j] && grid[n-1][j] == 1){
                dfs(n-1,j,grid,vis,delRow,delCol);
            }
        }

        for(int i = 0;i<n;i++){
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i,0,grid,vis,delRow,delCol);
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1){
                dfs(i,m-1,grid,vis,delRow,delCol);
            }
        }

        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0) cnt++;
            }
        }

        return cnt;
    }
};