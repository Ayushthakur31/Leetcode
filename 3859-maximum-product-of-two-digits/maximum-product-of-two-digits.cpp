class Solution {
public:
    int maxProduct(int n) {
        int ans = 0;
        int max1 = 0;
        int max2 = 0;
         while(n > 0){
            int x = n % 10;
            n /= 10;
           
           if(x >= max1){
            max2 = max1;
            max1 = x;
           }
           else if(x > max2){
            max2 = x;
           }
        }
         ans = max1 * max2;
         return ans;
    }
};