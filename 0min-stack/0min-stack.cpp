class MinStack {
public:
    vector<int> data;
    int mini;
    int count;
    MinStack() {
        
    }
    
    void push(int val) {
        data.push_back(val);
        if(data.size() == 1){
            mini = data[0];
            count = 1;
        }else {
            if(val < mini){
                mini = val;
                count = 1;
            }else if (val == mini){
                count++;
            }
        }
    }
    
    void pop() {
        int val = top();
        data.pop_back();
        if(val == mini){
            count--;
            if (count == 0){
                mini = data[0];
                for (int i : data){
                    if (i < mini){
                        mini = i;
                        count = 1;
                    }
                }
            }
        }
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */