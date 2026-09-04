class Solution {
public:
    long long mod = 1e9 + 7;
    long long f(long long base,long long exp){
        long long result = 1;
        while(exp > 0){
            if(exp % 2 == 1){
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp/=2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long evenPos = (n+1)/2;
        long long oddPos = n/2;
        long long ans = f(5,evenPos);
        ans = (ans * f(4,oddPos))%mod;
        return ans;
    }
};