class Solution {
public:
    static unordered_map<char,int> alpha;
    static bool by(const string &a, const string &b){
        int i = 0, j = 0;
        while(i < a.size() && j< b.size()){
            if(alpha[a[i]] < alpha[b[j]])return true;
            if(alpha[a[i]] > alpha[b[j]])return false;
            i++;
            j++;
        }
        if(i < a.size())return false;
        if(j < b.size())return true;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int count = 0;
        for(char c : order){
            alpha[c] = count++;
        }
        vector<string> other = words;
        sort(words.begin(),words.end(),by);
        for(int i = 0; i<other.size(); ++i){
            if(other[i]!=words[i])return false;
        }
        return true;
    }
};
unordered_map<char, int> Solution::alpha;
