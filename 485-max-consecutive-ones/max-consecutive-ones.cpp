class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int result =0;
        vector<int> ans;
        for(int i = 0;i < n;i++){
            if(nums[i] != 0){
                cnt++;
            }
            else{
                ans.push_back(cnt);
                cnt=0;
            }
            ans.push_back(cnt);
        }
        result =*max_element(ans.begin(),ans.end());
        return result;
    }
};