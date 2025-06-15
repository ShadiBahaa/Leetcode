class TimeMap {
public:
    map<string,vector<pair<int,string>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key))return "";
        vector<pair<int,string>>& cur = mp[key];
        int left = 0;
        int right = cur.size() - 1;
        int ans = -1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(cur[mid].first <= timestamp){
                ans = mid;
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        if(ans == -1)return "";
        return cur[ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */