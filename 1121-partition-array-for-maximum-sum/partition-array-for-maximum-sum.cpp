class Solution {
public:
//Recursion
    // int f(int ind,vector<int> &arr,int k){
    //     int len = 0,maxi = -1e9,sum = 0;
    //       int maxans = 0;
    //     int n = arr.size();
    //     if(ind == n)return 0;
    //     for(int i = ind;i <  min((int)arr.size(),ind+k);i++){
    //         len++;
    //         maxi = max(maxi,arr[i]);
    //         sum = (len * maxi) + f(i+1,arr,k);
    //        maxans = max(maxans,sum);
    //     }
    //    return maxans;
    // }
    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //     return f(0,arr,k);
    // }

//Memoization 
    int f(int ind,vector<int> &arr,int k,vector<int> &dp){
        int len = 0,maxi = -1e9,sum = 0;
          int maxans = 0;
        int n = arr.size();
        if(ind == n)return 0;
        if(dp[ind] != -1) return dp[ind];
        for(int i = ind;i <  min((int)arr.size(),ind+k);i++){
            len++;
            maxi = max(maxi,arr[i]);
            sum = (len * maxi) + f(i+1,arr,k,dp);
           maxans = max(maxans,sum);
        }
       return dp[ind] = maxans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,-1);
        return f(0,arr,k,dp);
    }    

};
