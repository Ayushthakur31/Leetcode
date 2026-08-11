class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       unordered_set<int> comm(nums1.begin(),nums1.end());
       unordered_set<int> result;

       for(auto num : nums2){
        if(comm.count(num)) result.insert(num);
       }
       return vector<int> (result.begin(),result.end());
    }
};