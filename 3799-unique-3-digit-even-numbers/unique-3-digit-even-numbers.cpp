class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> st;
        for(int i = 0;i < digits.size();i++){
            for(int j = 0;j < digits.size();j++){
                for(int k = 0;k < digits.size();k++){
                    if(i !=j && j != k && k != i && digits[i] != 0 && digits[k] % 2 == 0){
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                        st.insert(num);
                    }
                }
            }
        }
        return st.size();
    }
};