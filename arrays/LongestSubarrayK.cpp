#include<iostream>
#include<algorithm>
#include<climits>
#include<math.h>
#include<map>
using namespace std;

int longestSubarrayK(vector<int>& a,int k){
    int sum = 0;
    int maxLen = 0;
    map<int,int>prefixSumMap;
    for(int i = 0;i<a.size();i++){
        sum += a[i];
        if(sum == k){
            maxLen = max(maxLen,i+1);
        }
        int rem = sum - k;
        if(prefixSumMap.find(rem) != prefixSumMap.end()){
            int len = i - prefixSumMap[rem];
            maxLen = max(maxLen,len);
        }
        if(prefixSumMap.find(sum) == prefixSumMap.end()){
            prefixSumMap[sum] = i;
        }
    }
    return maxLen;
}