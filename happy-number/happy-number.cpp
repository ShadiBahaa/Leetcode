class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> targets;
        long long i = 1;
        while(i<=1000000000){
            targets.insert(i);
            i*=10;
        }
        int cur = n;
        unordered_set<int> prev;
        while(true){
            int sum = 0;
            while(cur!=0){
                int digit = cur%10;
                cur /= 10;
                sum += digit*digit;
            }
            if(prev.count(sum)){
                return false;
            }
            if(targets.count(sum)){
                return true;
            }
            prev.insert(sum);
            cur = sum;
        }
        return false;
    }
};