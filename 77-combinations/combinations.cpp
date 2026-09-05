class Solution {
public:
    void f(int ind,int k,int n,vector<int>& ds,vector<vector<int>>& ans){
        if(ds.size() == k){
            ans.push_back(ds);
            return;
        }
        for(int i = ind;i <= n;i++){
            ds.push_back(i);
            f(i+1,k,n,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> ds;
        vector<vector<int>> ans;
        f(1,k,n,ds,ans);
        return ans;
    }
};