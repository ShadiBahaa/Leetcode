class Solution {
public:
    vector<vector<int>> book;
    int width;
    map<int,int> mp;
    int dp(/*int i*/){
        /*if (i >= book.size())return 0;
        if (mp.count(i))return mp[i];
        int ans = INT_MAX;
        int cur_width = 0, cur_hight = 0;
        for (int k = i; k<book.size(); ++k){
            cur_width += book[k][0];
            cur_hight = max(cur_hight,book[k][1]);
            if (cur_width > width)break;
            ans = min(ans,cur_hight + dp(k+1));
        }
        return mp[i] = ans;*/
        mp[book.size()] = 0;
        for (int i = book.size()-1; i>=0; --i){
            mp[i] = INT_MAX;
            int cur_width = 0, cur_hight = 0;
            for (int k = i; k<book.size(); ++k){
                cur_width += book[k][0];
                cur_hight = max(cur_hight,book[k][1]);
                if (cur_width > width)break;
                mp[i] = min(mp[i],cur_hight + mp[k+1]);
            }
        }
        return mp[0];
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        book = books;
        width = shelfWidth;
        return dp(/*0*/);
        
    }
};