class Solution {
public:
vector<int> f(int n){
    if(n == 0) return {1};
    vector<int> prev = f(n-1);
    vector<int> curr(n+1,1);
    for(int i = 1;i < n;i++){
        curr[i] = prev[i-1] + prev[i]; 
    }
    return curr;
}
vector<vector<int>> generate(int numRows) {
       vector<vector<int>> ans;
       for(int i = 0;i < numRows;i++){
        ans.push_back(f(i));
       }
       return ans;
    }
};