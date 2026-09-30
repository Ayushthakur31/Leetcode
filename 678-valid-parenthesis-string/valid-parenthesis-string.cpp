class Solution {
public:
    bool  f(string& s,int ind,int cnt,vector<vector<int>>& dp){
        int n = s.size();
        if(cnt < 0) return false;
        if(dp[ind][cnt] != -1) return dp[ind][cnt];
        if(ind == n) return (cnt==0);
        if(s[ind] == '(') return f(s,ind+1,cnt+1,dp);
        if(s[ind] == ')') return f(s,ind+1,cnt-1,dp);
        return dp[ind][cnt] = f(s,ind+1,cnt+1,dp) || f(s,ind+1,cnt-1,dp) || f(s,ind+1,cnt,dp);
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(s,0,0,dp);
    }
};