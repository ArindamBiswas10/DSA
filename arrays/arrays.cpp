//Largest element in an array
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int LargestElement(vector<int>& arr){
    int largest = arr[0];
    for(int i = 1;i<arr.size();i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    return largest;
}

//Second Largest element in an array
//same logic for smallest and second smallest btw

int SLargest(vector<int> & arr){
    int largest = arr[0];
    int sLargest = -1;
    for(int i = 1;i<arr.size();i++){
        if(arr[i]>largest){
            sLargest = largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>sLargest){
            sLargest = arr[i];
        }
    }

    return sLargest;
}

//isSorted

int isSorted(int n, vector<int>& a){
    for(int i = 1;i<n;i++){
        if(a[i-1]<a[i]){

        }
        else{return false;}
    }
    return true;
}

//Longest subarray with sum K(both +ve and -ve and 0)

int longestSubarraySum(vector<int>& a,long long k){
    map<long long,int> prefixSum;
    long long sum = 0;
    int maxLen = 0;
    for(int i = 0; i<a.size();i++){
        sum += a[i];
        if(sum == k){
            maxLen = max(maxLen,i+1);
        }
        long long rem = sum - k;
        if(prefixSum.find(rem) != prefixSum.end()){
            int len = i - prefixSum[rem];
            maxLen = max(maxLen,len);
        }
        if(prefixSum.find(sum) == prefixSum.end()){
            prefixSum[sum] = i;
        }
    }
    return maxLen;
}


//Two-Sum

vector<int> two_sum(vector<int>arr,int target){
   unordered_map<int,int> mpp;
   for(int i = 0;i<arr.size();i++){
    int compliment  = target - arr[i];
    if(mpp.find(compliment) != mpp.end()){
        return {mpp[compliment],i};
    }
    mpp[arr[i]] = i;
   }

   return {-1,-1};
}