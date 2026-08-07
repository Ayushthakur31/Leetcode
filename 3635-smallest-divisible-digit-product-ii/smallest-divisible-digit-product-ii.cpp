class Solution {
public:
    // digit -> {count of 2s, count of 3s, count of 5s, count of 7s}
    array<int,4> DF[10] = {
        {0,0,0,0}, // 0 (unused, zero-free)
        {0,0,0,0}, // 1
        {1,0,0,0}, // 2
        {0,1,0,0}, // 3
        {2,0,0,0}, // 4
        {0,0,1,0}, // 5
        {1,1,0,0}, // 6
        {0,0,0,1}, // 7
        {3,0,0,0}, // 8
        {0,2,0,0}  // 9
    };

    array<int,4> primeCount(long long t, bool &ok) {
        array<int,4> c = {0,0,0,0};
        int primes[4] = {2,3,5,7};
        for (int i = 0; i < 4; i++) {
            while (t % primes[i] == 0) {
                t /= primes[i];
                c[i]++;
            }
        }
        ok = (t == 1);
        return c;
    }

    // map digit(2..9) -> how many of that digit, packed to minimize digit count
    array<int,8> factorCount(array<int,4> c) {
        int c2 = c[0], c3 = c[1], c5 = c[2], c7 = c[3];
        int f8 = c2 / 3, r2 = c2 % 3;
        int f9 = c3 / 2, f3 = c3 % 2;
        int f4 = r2 / 2, f2 = r2 % 2;
        int f6 = 0;
        if (f2 == 1 && f3 == 1) { f2 = 0; f3 = 0; f6 = 1; }
        if (f3 == 1 && f4 == 1) { f2 = 1; f6 = 1; f3 = 0; f4 = 0; }
        // index by digit: [2,3,4,5,6,7,8,9]
        return {f2, f3, f4, c5, f6, c7, f8, f9};
    }

    int totalDigits(const array<int,8> &f) {
        int s = 0;
        for (int v : f) s += v;
        return s;
    }

    string build(const array<int,8> &f) {
        string res;
        for (int d = 2; d <= 9; d++)
            res += string(f[d - 2], char('0' + d));
        return res;
    }

    string smallestNumber(string num, long long t) {
        bool ok;
        array<int,4> req = primeCount(t, ok);
        if (!ok) return "-1";

        array<int,8> minF = factorCount(req);
        int minLen = totalDigits(minF);
        int n = num.size();

        if (minLen > n) {
            // The minimal digit set is already longer than num, so any
            // number built from it is automatically greater than num.
            // No padding needed -- just return it directly.
            return build(minF);
        }

        array<int,4> prefix = {0,0,0,0};
        for (char ch : num) {
            int d = ch - '0';
            for (int i = 0; i < 4; i++) prefix[i] += DF[d][i];
        }

        int firstZero = num.find('0');
        if (firstZero == (int)string::npos) {
            firstZero = n;
            bool subset = true;
            for (int i = 0; i < 4; i++)
                if (req[i] > prefix[i]) { subset = false; break; }
            if (subset) return num;
        }

        for (int i = n - 1; i >= 0; i--) {
            int d = num[i] - '0';
            for (int k = 0; k < 4; k++) prefix[k] -= DF[d][k];

            int space = n - 1 - i;
            if (i > firstZero) continue;

            for (int big = d + 1; big <= 9; big++) {
                array<int,4> rem;
                for (int k = 0; k < 4; k++) {
                    int step1 = max(0, req[k] - prefix[k]);
                    rem[k] = max(0, step1 - DF[big][k]);
                }
                array<int,8> nf = factorCount(rem);
                int need = totalDigits(nf);
                if (need <= space) {
                    string result = num.substr(0, i);
                    result += char('0' + big);
                    result += string(space - need, '1');
                    result += build(nf);
                    return result;
                }
            }
        }

        array<int,8> ext = factorCount(req);
        return string(n + 1 - totalDigits(ext), '1') + build(ext);
    }
};
