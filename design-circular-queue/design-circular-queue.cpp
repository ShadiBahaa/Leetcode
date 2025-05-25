class MyCircularQueue {
public:
    vector<int> data;
    int head = -1;
    int tail = -1;
    int k;
    MyCircularQueue(int k) {
        this->k = k;
        data.resize(k);
    }
    
    bool enQueue(int value) {
        if(!isFull()){
            if(head == -1)head = 0;
            tail = (tail + 1) %k;
            data[tail] = value;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        cout<<head<<" "<<tail<<endl;
        if(!isEmpty()){
            if(head == tail){
                head = -1;
                tail = -1;
            }else head = (head + 1)%k;
            return true;
        }
        return false;
    }
    
    int Front() {
        
        if (!isEmpty())return data[head];
        return -1;
    }
    
    int Rear() {
        if (!isEmpty()) return data[tail];
        return -1;
    }
    
    bool isEmpty() {
        return head == tail && head == -1;
    }
    
    bool isFull() {
        return ((tail+1)%k == head);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */