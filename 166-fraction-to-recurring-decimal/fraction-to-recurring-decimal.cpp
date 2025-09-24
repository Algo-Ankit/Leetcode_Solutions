class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res;
        if ((numerator < 0) ^ (denominator < 0)) res.push_back('-');

        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        long long integerPart = num / den;
        res += to_string(integerPart);

        long long rem = num % den;
        if (rem == 0) return res;

        res.push_back('.');
        unordered_map<long long, int> seen;

        while (rem != 0) {
            if (seen.count(rem)) {
                res.insert(seen[rem], "(");
                res.push_back(')');
                break;
            }
            seen[rem] = res.size();
            rem *= 10;
            res.push_back('0' + rem / den);
            rem %= den;
        }
        return res;
    }
};
