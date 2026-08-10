class Solution {
public:
//Recursive
    // bool f(int n){
    //     if( n == 0) return 0;
    //     for(int i = 1;i * i <= n;i++){
    //         if(!f(n-i*i)) return true;
    //     }
    //     return false;
    // }
    // bool winnerSquareGame(int n) {
    //     return f(n);
    // }

//Memoisation
    //   bool f(int n,vector<int> &dp){
    //     if( n == 0) return 0;
    //     if(dp[n] != -1) return dp[n];
    //     for(int i = 1;i * i <= n;i++){
    //         if(!f(n-i*i,dp)) return dp[n] =  true;
    //     }
    //     return dp[n] = false;
    // }
    // bool winnerSquareGame(int n) {
    //     vector<int> dp(n+1,-1);
    //     return f(n,dp);
    // } 

//Tabulation
     bool winnerSquareGame(int n) {
        vector<int> dp(n+1,false);
        dp[0] = false;
        for(int j = 1;j <= n;j++){
        for(int i = 1;i * i <= j;i++){
            if(!dp[j - i*i]) {
                dp[j] =  true;
                break;
        }
        }
        }
        return dp[n];
    }        
};