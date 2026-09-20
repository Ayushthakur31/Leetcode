class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 0;i < s.size();i++){
            int rev =  'z' - s[i] + 1;
            int x = (i+1)*rev;
            sum += x;
        }
        return sum;
    }
};