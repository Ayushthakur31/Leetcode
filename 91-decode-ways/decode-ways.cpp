class Solution {
public:
//Recursion
    // int f(int i,string& s){
    //     if(i == s.size()) return 1;
    //     if(s[i] == '0') return 0;

    //     int ans = f(i+1,s);

    //     if(i+1 < s.size()){
    //         int num = (s[i] - '0') * 10 + s[i+1] - '0';
    //     if(num >=10 && num <= 26)
    //     ans += f(i+2,s);
    //     }
    //     return ans;
    // }
    // int numDecodings(string s) {
    //     return f(0,s);
    // }

//Memoisation
    // int f(int i,string& s,vector<int>& dp){
    //     if(i == s.size()) return 1;
    //     if(s[i] == '0') return 0;
    //     if(dp[i] != -1) return dp[i];
    //     int ans = f(i+1,s,dp);

    //     if(i+1 < s.size()){
    //         int num = (s[i] - '0') * 10 + s[i+1] - '0';
    //     if(num >=10 && num <= 26)
    //     ans += f(i+2,s,dp);
    //     }
    //     return dp[i] = ans;
    // }
    // int numDecodings(string s) {
    //     int n = s.size();
    //     vector<int> dp(n+1,-1);
    //     return f(0,s,dp);
    // }  

//Tabulation
//     int numDecodings(string s) {
//         int n = s.size();
//         vector<int> dp(n+1,0);
//         dp[n] = 1;
//         for(int i = n-1;i >= 0;i--){
//             if(s[i] == '0') {
//             dp[i] = 0;
//             continue;
// }
//          dp[i] = dp[i+1];

//         if(i+1 < n){
//             int num = (s[i] - '0') * 10 + s[i+1] - '0';
//         if(num >=10 && num <= 26)
//         dp[i] += dp[i+2];
//         }
//         }
//         return dp[0];
//     }      

//Space Optimisation
     int numDecodings(string s) {
        int n = s.size();
        int next2 = 0;
        int next1 = 1;
        for(int i = n-1;i >= 0;i--){
            int curr = 0;
         if(s[i] != '0')
         curr = next1;

        if(i+1 < n){
            int num = (s[i] - '0') * 10 + s[i+1] - '0';
        if(num >=10 && num <= 26)
        curr += next2;
        }
        next2 = next1;
        next1 = curr;
        }
        return next1;
    }    
};