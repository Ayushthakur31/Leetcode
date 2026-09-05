class Solution {
public:
     void f(int ind,int target,vector<int>& arr,vector<int>& ds,vector<vector<int>>& ans){
        if(ind == arr.size()){
            if(target == 0)
                ans.push_back(ds);
                return;
        }
        if(arr[ind] <= target){
            ds.push_back(arr[ind]);
            f(ind,target-arr[ind],arr,ds,ans);
            ds.pop_back();
        }
        f(ind+1,target,arr,ds,ans);
     }      
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<int> arr = candidates;
       vector<vector<int>> ans;
       vector<int> ds;
       f(0,target,arr,ds,ans);
       return ans;
    }
};