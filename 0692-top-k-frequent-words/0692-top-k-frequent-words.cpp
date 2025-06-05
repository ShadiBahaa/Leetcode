struct CustomCompare {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first != b.first) {
            return a.first < b.first;  // max heap on int
        } else {
            return a.second > b.second;  // min heap on string
        }
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, CustomCompare> pq;
        map<string,int> mp;
        for (string word : words){
            mp[word]++;
        }
        for(auto it : mp){
            pq.push({it.second,it.first});
        }
        vector<string> v;
        while(true){
            int x = pq.top().first;
            vector<string> sub;
            while(true){
                if(k==0)break;
                if(pq.top().first == x){
                    sub.push_back(pq.top().second);
                    pq.pop();
                    k--;
                }else {
                    break;
                }
            }
            if(sub.size()>1){
                sort(sub.begin(),sub.end());
            }
            for(string ele : sub){
                v.push_back(ele);
            }
            if(k == 0)break;
        }
        return v;
    }
};