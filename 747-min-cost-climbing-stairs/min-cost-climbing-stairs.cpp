class Solution {
public:
//Recursion
    // int f(int n,vector<int> &cost){
    //     if(n <= 1) return cost[n];
    //     return cost[n] + min(f(n-1,cost),f(n-2,cost));
    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //      return  min(f(n-1,cost),f(n-2,cost));
    // }

//memoization
    // int f(int n,vector<int> &cost,vector<int>& dp){
    //     if(n <= 1) return cost[n];
    //     if(dp[n] != -1) return dp[n];
    //     return dp[n] = cost[n] + min(f(n-1,cost,dp),f(n-2,cost,dp));
    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     vector<int> dp(n+1,-1);
    //      return  min(f(n-1,cost,dp),f(n-2,cost,dp));
    // }    

//Tabulation
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n <= 1) return cost[0];
        vector<int> dp(n,0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2;i < n;i++){
           dp[i] =  cost[i] + min(dp[i-1],dp[i-2]);
        }
         return  min(dp[n-1],dp[n-2]);
    }      
};