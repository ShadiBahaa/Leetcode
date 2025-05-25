class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int sz = q1.size();
        int i = 0;
        int val;
        while(!q1.empty()){
            i++;
            if(i==sz){
              val = q1.front();
              q1.pop();
              break;
            }
            q2.push(q1.front());
            q1.pop();
        }
        
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return val;
    }
    
    int top() {
        int sz = q1.size();
        int i = 0;
        int val;
        while(!q1.empty()){
            i++;
            if(i==sz){
              val = q1.front();
            }
            q2.push(q1.front());
            q1.pop();
        }
        
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return val;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */