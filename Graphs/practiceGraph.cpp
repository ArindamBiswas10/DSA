#include<iostream>
#include<algorithm>
#include<climits>
#include<map>
using namespace std;

class NumOfProvinces{

    private:
    void dfs(int node,vector<int>adjLs[],vector<int> &vis){
        vis[node] = 1;
        for(auto it: adjLs[node]){
            if(!vis[it]){
                dfs(node,adjLs,vis);
            }
        }

    }
public:
int numProvinces(vector<vector<int>> grid,int V){
    int n = grid.size();
    int m = grid[0].size();
    vector<int> adjLs[V];
    for(int i = 0; i<V;i++){
        for(int j = 0;j<V;j++){
            adjLs[i].push_back(j);
            adjLs[j].push_back(i);
        }
    }
    int cnt = 0;
    vector<int> vis(V,0);
    for(int i = 0;i<V;i++){
        if(!vis[i]){
            cnt++;
            dfs(i,adjLs,vis);
        }
    }

    return cnt;
}
};

class numOfIslands{
    private:
    void bfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&vis){
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delRow[] = {-1,0,+1,0};
            int delCol[] = {0,+1,0,-1};
            for(int i = 0;i<4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow>=0 && nRow<n && nCol>0 && nCol<m && vis[nRow][nCol] != 1 && grid[nRow][nCol] == '1'){
                    vis[nRow][nCol] = 1;
                    q.push({nRow,nCol});
                }
            }
        }
    }
    public:
    int numOfIsland(vector<vector<int>> grid){
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

class FloofFill{
    private:
    void dfs(int row,int col,vector<vector<int>>& ans,vector<vector<int>>& image,int iniColor,int newColor,int delRow[],int delCol[]){
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol] == iniColor && ans[nRow][nCol] != newColor){
                dfs(nRow,nCol,ans,image,iniColor,newColor,delRow,delCol);
            }
        }
    }
    public:
    vector<vector<int>> floodfill(vector<vector<int>> image,int sr,int sc,int newColor){
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        dfs(sr,sc,ans,image,iniColor,newColor,delRow,delCol);
        return ans;
    }
};


class RottenOranges{
    public:
    int rottenOranges(vector<vector<int>>grid){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        //{{r,c},t}
        int vis[n][m];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        int tm = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t);
            q.pop();
            int delRow[] = {-1,0,+1,0};
            int delCol[] = {0,+1,0,-1};
            for(int i =0;i<4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && vis[nRow][nCol] != 2 && grid[nRow][nCol] == 1){
                    vis[nRow][nCol] = 2;
                    q.push({{nRow,nCol},t+1});
                }
            }
        }

        return tm;

        
    }
};