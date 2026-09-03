#include<iostream>
#include<algorithm>
#include<math.h>
#include<algorithm>
using namespace std;

class Solution{
    private:
    void dfs(int row,int col,vector<vector<char>>& mat,vector<vector<int>>&vis,int delRow[],int delCol[]){
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && vis[nRow][nCol] != 1 && mat[nRow][nCol] == 'O'){
                dfs(nRow,nCol,mat,vis,delRow,delCol);
            }

        }

    }
    public:
    vector<vector<char>>fill(int n, int m,vector<vector<char>> mat){
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j = 0;j<m;j++){
            if(!vis[0][j] && mat[0][j] == 'O'){
                dfs(0,j,mat,vis,delRow,delCol);
            }
            if(!vis[n-1][j] && mat[n-1][j] == 'O'){
                dfs(n-1,j,mat,vis,delRow,delCol);
            }
        }

        for(int i = 0;i<n;i++){
            if(!vis[i][0] && mat[i][0] == 'O'){
                dfs(i,0,mat,vis,delRow,delCol);
            }
            if(!vis[i][m-1] && mat[i][m-1] == 'O'){
                dfs(i,m-1,mat,vis,delRow,delCol);
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }

};


