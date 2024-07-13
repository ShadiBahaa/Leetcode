class MyHashMap {
public:
    int *arr = nullptr;
    MyHashMap() {
        arr = new int [1e6+5];
        for (int i = 0; i<(1e6 + 5); ++i){
            arr[i] = -1;
        }
    }
    
    void put(int key, int value) {
       
        arr[key] = value;
    }
    
    int get(int key) {
        //cout<<"key is "<<key<<" val is "<<arr[key]<<endl;
        return arr[key];
    }
    
    void remove(int key) {
        arr[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */