class Solution {
public:
//Recursion
    //  int f(int i,vector<int> &stoneValue){
    //     int n = stoneValue.size();
    //     if(i >= n) return 0;
    //     int take = 0;
    //     int maxi = -1e9;

    //     for(int j = 0;j < 3 && j+i < n;j++){
    //         take += stoneValue[i+j];
    //         maxi = max(maxi, take - f(i+j+1,stoneValue));
    //     }
    //     return maxi;
    // }
    // string stoneGameIII(vector<int>& stoneValue) {
    //     int diff = f(0,stoneValue);
    //     if(diff > 0) return "Alice";
    //     if(diff < 0) return "Bob";
    //     return "Tie";
    // }

//Memoization
    //  int f(int i,vector<int> &stoneValue,vector<int> &dp){
    //     int n = stoneValue.size();
    //     if(i >= n) return 0;
    //     if(dp[i] != -1) return dp[i];
    //     int take = 0;
    //     int maxi = -1e9;

    //     for(int j = 0;j < 3 && j+i < n;j++){
    //         take += stoneValue[i+j];
    //         maxi = max(maxi, take - f(i+j+1,stoneValue,dp));
    //     }
    //     return maxi;
    // }
    // string stoneGameIII(vector<int>& stoneValue) {
    //    int n = stoneValue.size();
    //     vector<int> dp(n,-1);
    //     int diff = f(0,stoneValue,dp);
    //     if(diff > 0) return "Alice";
    //     if(diff < 0) return "Bob";
    //     return "Tie";
    // }    

//Tabulation
    string stoneGameIII(vector<int>& stoneValue) {
       int n = stoneValue.size();
        vector<int> dp(n+1,0);
        for(int i = n-1;i >= 0;i--){
            int take = 0;
            int maxi = -1e9;

        for(int j = 0;j < 3 && j+i < n;j++){
            take += stoneValue[i+j];
            maxi = max(maxi, take - dp[i+j+1]);
        }
            dp[i] = maxi;
        }
        int diff = dp[0];
        if(diff > 0) return "Alice";
        if(diff < 0) return "Bob";
        return "Tie";
    }        
};