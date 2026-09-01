#include<iostream>
#include<algorithm>
#include<climits>
#include<math.h>
using namespace std;

class Solution{
    public:
    int RottenOranges(vector<vector<int>> grid){
        int n = grid.size();
        int m = grid[0].size();
        //{{r,c},t}
        queue<pair<pair<int,int>,int>> q;
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
            for(int i = 0;i<4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && vis[nRow][nCol] != 2  && grid[nRow][nCol] == 1){
                    q.push({{nRow,nCol} , t + 1});
                    vis[nRow][nCol] = 1;
                }
            }
        }

        return tm;

        
    }
};