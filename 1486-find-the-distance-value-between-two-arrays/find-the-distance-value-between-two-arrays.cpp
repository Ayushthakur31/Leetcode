class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int i=0,j=0;
        int dist = 0;
        for(i=0;i<arr1.size();i++){
            bool valid = true;
            for(j=0;j<arr2.size();j++){
                if(abs(arr1[i] - arr2[j]) <= d){
                    valid = false;
                    break;
                }
            }
            if(valid == true) dist++;
        }
        return dist;
    }
};