class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int i : nums){
            st.insert(i);
        }
        int multiple = k;
        while(st.count(multiple)){
            multiple += k;
        }
        return multiple;
    }
};