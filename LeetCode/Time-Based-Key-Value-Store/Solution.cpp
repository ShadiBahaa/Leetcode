class TimeMap {
public:
    map<string,set<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key))
        {
            return "";
        }
        std::set<pair<int,string>> & s = mp[key];
        auto it = s.lower_bound({timestamp,""});
        if(it == s.end()){
            it--;
            return it->second;
        }else {
            if(it->first > timestamp){
                if(it == s.begin())return "";
                else it--;
            }
        }
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */