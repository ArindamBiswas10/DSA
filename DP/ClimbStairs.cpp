//So climbing stairs can be done using recursion and can be made better with memoization and tabulation. The idea is to find the minimum energy required to reach the top of the stairs. The energy required to jump from one stair to another is the absolute difference of the heights of the two stairs. The frog can jump either one or two stairs at a time.
#include<iostream>
#include<vector>
using namespace std;

//Basic Rcursion
//Same as fibonacci series
class Recursion{
    public:
    int climbStairs(int n){
        if(n==0 || n == 1) return 1;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};


//Memoization
class Solution {
    public:
    int solve(int ind,vector<int>& dp){
        if(ind<=1) return 1;

        if(dp[ind] != -1) return dp[ind];
        int left = solve(ind - 1, dp);
        int right = solve(ind - 2,dp);

        return dp[ind] = left + right;

    }

    int climbStairs(int n){
        vector<int> dp(n + 1,-1);
        return solve(n,dp);
    }
};

//Tabulation
class Tabulation{
    public:
    int climbStairs(int n){
        vector<int> dp(n + 1,0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2;i<=n;i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};


int main(){
    Solution sol;
    sol.climbStairs(5);
    return 0;
}