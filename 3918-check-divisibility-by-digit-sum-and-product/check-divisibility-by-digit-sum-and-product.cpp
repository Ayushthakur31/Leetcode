class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int sum = 0;
        int product = 1;
        while(n > 0){
        sum += n % 10;
        product *= n % 10;
        n /= 10;
        }
        int currsum = sum + product;
       return original % currsum == 0;
    }
};