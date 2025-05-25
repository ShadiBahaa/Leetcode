class MyHashSet {
public:
    vector<vector<int>> data;
    MyHashSet() {
        data.resize(1000);
    }
    
    void add(int key) {
        int index = key%1000;
        for (int i = 0; i<data[index].size(); ++i){
            if(data[index][i]==key)return;
        }
        data[index].push_back(key);
    }
    
    void remove(int key) {
        int index = key%1000;
        for(int i = 0; i<data[index].size(); ++i){
            if(data[index][i]==key){
                data[index].erase(data[index].begin() + i);
            }
        }
    }
    
    bool contains(int key) {
        int index = key%1000;
        for (int i : data[index]){
            if(i==key)return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */