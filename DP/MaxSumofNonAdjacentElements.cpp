
#include<iostream>
#include<vector>
using namespace std;
class Solution{

public:
    int maxSumofNonAdjacentElements(vector<int>& arr,int n){

        if(n == 0) return 0;
        if(n == 1) return arr[0];

        int prev = arr[0];
        int prev2 = 0;

        for(int i = 1;i<n;i++){
            int take = arr[i];
            if(i>1) take += prev2;
            int notTake = 0 + prev;
            int curi = max(take, notTake);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};