class Solution {
public:
    static bool comp(vector<int> val1,vector<int> val2){
        return val1[1] < val2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end(),comp);
        int cnt = 1;
        int lastendtime = pairs[0][1];
        for(int i = 1 ;i < n;i++){
            if(pairs[i][0] > lastendtime){
                cnt = cnt + 1;
                lastendtime = pairs[i][1];
            }
        }
        return cnt;
    }
};