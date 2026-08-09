class Solution {
public:
    // double minPrice(vector<int>& prices, vector<int>& discounts) {
    //     double mini = 1e18;
    //     for(int p = 0;p < prices.size();p++){
    //         for(int d = 0;d < discounts.size();d++){
    //             double cost = (prices[p] * (100.0 - discounts[d])) / 100.0;
    //             mini = min(mini,cost);
    //         }
    //     }
    //     return mini;
    // }

    double minPrice(vector<int>& prices, vector<int>& discounts) {
    sort(prices.rbegin(),prices.rend());
    sort(discounts.rbegin(),discounts.rend());

        double ans = 0;
        for(int price : prices) ans+= price;

        int cost = min(prices.size(),discounts.size());

        for(int i = 0; i < cost;i++){
            ans -= prices[i] * discounts[i] / 100.0;
        }
        return ans;
    }
};