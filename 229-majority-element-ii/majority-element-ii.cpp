class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int num : nums){
            mpp[num]++;
        }
        vector<int> ans;
        for(auto key : mpp){
            if(key.second > nums.size()/3){
                ans.push_back(key.first);
            }
        }
        return ans;
    }
};