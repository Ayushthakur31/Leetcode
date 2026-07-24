class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        bitset<MAXX> two, three;

        for (int a : nums)
            for (int b : nums)
                two[a ^ b] = 1;

        for (int x = 0; x < MAXX; x++) {
            if (!two[x]) continue;
            for (int c : nums)
                three[x ^ c] = 1;
        }

        return three.count();
    }
};