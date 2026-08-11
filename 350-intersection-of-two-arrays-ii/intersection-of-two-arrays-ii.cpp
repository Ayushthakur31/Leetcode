class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp;
        vector<int> ans;

        for(auto n : nums1){
            mpp[n]++;
        }
        for(auto n : nums2){
            if(mpp[n] > 0) ans.push_back(n);
            mpp[n]--; 
        }
        return ans;
    }    
};