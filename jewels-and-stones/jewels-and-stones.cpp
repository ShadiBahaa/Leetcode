class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        for(char c : stones){
            for(char d : jewels){
                if(c==d)count++;
            }
        }
        return count;
    }
};