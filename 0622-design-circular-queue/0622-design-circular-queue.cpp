class MyCircularQueue {
public:
    vector<int> q;
    int start = 0, end = -1;
    int size;
    MyCircularQueue(int k) {
        q.resize(k);
        size = k;
    }
    
    bool enQueue(int value) {
        
        if(isFull()) return false;
        if(end == -1)end = 0;
        q[end] = value;
        end++;
        end%=size;
        
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        
        start++;
        start%=size;
        if(start == end){
            start = 0;
            end = -1;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[start];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        int last = end - 1;
        if(last == -1) last = size - 1;
        return q[last];
    }
    
    bool isEmpty() {
        return end == -1;
    }
    
    bool isFull() {
        return start == end;
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