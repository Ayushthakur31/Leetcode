class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(),
     [](vector<int>& a, vector<int>& b) {
         return a[1] > b[1];
     });
        int n = boxTypes.size();
        int k = truckSize;
        int l = 0;
        int sum = 0;
        while(l < n && k > 0){
            int boxes = min(boxTypes[l][0],k);
            sum += boxes * boxTypes[l][1];
            k -= boxes;
            l++;
        }
        return sum;
    }
};