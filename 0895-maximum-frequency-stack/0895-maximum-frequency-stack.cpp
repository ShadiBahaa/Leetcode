class FreqStack {
public:
   
    map<int,int> num_freq;
    map<int,vector<int>> freq_num;
    int mx_freq;
    FreqStack() {
        mx_freq = 0;
    }
    
    void push(int val) {
        int cur_freq = num_freq[val] + 1;
        num_freq[val] += 1;
        if (cur_freq > mx_freq){
            mx_freq = cur_freq;
        }
        freq_num[cur_freq].push_back(val);
    }
    
    int pop() {
        int res = freq_num[mx_freq][freq_num[mx_freq].size()-1];
        num_freq[res]--;
        freq_num[mx_freq].pop_back();
        if (freq_num[mx_freq].size()==0)mx_freq-=1;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */