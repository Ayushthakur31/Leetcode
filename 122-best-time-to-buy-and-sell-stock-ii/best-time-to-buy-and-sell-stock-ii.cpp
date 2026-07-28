class Solution {
public:
//Memoization
    // int f(int ind,int buy,int n,vector<int> &prices,vector<vector<int>> &dp){
    //     if(ind == n) return 0;
    //     if(dp[ind][buy] != -1) return dp[ind][buy];
    //     int profit = 0;
    //     if(buy){
    //          profit = max(-prices[ind] + f(ind+1,0,n,prices,dp) , 0 + f(ind+1,1,n,prices,dp));
    //     }
    //     else{
    //         profit = max(prices[ind] + f(ind+1,1,n,prices,dp) , 0 + f(ind+1,0,n,prices,dp));
    //     }
    //     return dp[ind][buy] = profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //    int n = prices.size();
    //    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
    //     return f(0,1,n,prices,dp);

//Tabulation
    // int maxProfit(vector<int>& prices) {
    //    int n = prices.size();
    //    vector<vector<int>> dp(n+1,vector<int> (2,0));
    //    for(int ind = n-1;ind >= 0;ind--){
    //     for(int buy = 0;buy <= 1;buy++){
    //        int profit = 0;
    //     if(buy){
    //          profit = max(-prices[ind] + dp[ind+1][0] , 0 + dp[ind+1][1]);
    //     }
    //     else{
    //         profit = max(prices[ind] + dp[ind+1][1] , 0 +dp[ind+1][0]);
    //     }
    //         dp[ind][buy] = profit; 
    //     }
    //    }
    //    return dp[0][1];
    // }

// space optimisation
     int maxProfit(vector<int>& prices) {
       int n = prices.size();
        vector<int> prev(2,0);
        vector<int> curr(2,0);
       for(int ind = n-1;ind >= 0;ind--){
        for(int buy = 0;buy <= 1;buy++){
           int profit = 0;
        if(buy){
             profit = max(-prices[ind] + prev[0] , 0 + prev[1]);
        }
        else{
            profit = max(prices[ind] + prev[1] , 0 + prev[0]);
        }
            curr[buy] = profit; 
        }
        prev = curr;
       }
       return prev[1];
    }    
};