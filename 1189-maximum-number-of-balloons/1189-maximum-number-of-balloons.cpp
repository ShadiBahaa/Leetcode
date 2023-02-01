class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> mp;
        for (char c:text)mp[c]++;
        return min(mp['b'],min(mp['a'],min(mp['l']/2,min(mp['o']/2,mp['n']))));
    }
};