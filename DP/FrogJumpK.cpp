//so the original problem was with 2 jumps.

#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
using namespace std;

int fn(int ind,vector<int>& arr){
    if(ind == 0) return 0;

    int fs = fn(ind - 1,arr) + abs(arr[ind] - arr[ind-1]);

    if(ind>1) 
    int secstep = fn(ind - 2,arr) + abs(arr[ind] - arr[ind - 2]);

    return min(fs,secstep);
}

int frog(int index,vector<int>& data){
    if(index == 0) return 0;
    int firstStep = frog(index - 1, data) + abs(data[index] - data[index - 1]);
    if(index > 1){
        int secondStep = frog(index - 2, data) + abs(data[index] - data[index - 2]);
        return min(firstStep, secondStep);
    }
    return firstStep;
}

int frog(int i,vector<int>& data){
    if(i == 0) return 0;
    int firstStep = frog(i-1,data) + abs(data[i] - data[i-1]);
    if(i > 1){
        int secondStep = frog()
    }
}

int main(){
    int ind;
    cin>>ind;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    fn(ind,arr);
}

//can make better obv with dp memo and tabu or better optimized way

//Now for variation with K jumps

//the recurrence relation will be

/*fn(ind){
    if(ind == 0) return 0;

    min = INT_MIN;
    for(int j = 1;j<n;j++){
        if(ind-j>0)
        jumps = fn(ind - j) + abs(arr[ind] - arr[ind - j]);
    }
}*/

//Now we memoize and tabu this solution

class Kjumps{
    public:
    int FrogKjumps(){

    }
};