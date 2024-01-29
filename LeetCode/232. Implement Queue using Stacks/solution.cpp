class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    int peekEle;
    int numOfEle;
    MyQueue() {
        numOfEle=0;
        peekEle=0;
    }
    
    void push(int x) {
        if(numOfEle==0) peekEle=x;
        st1.push(x);
        numOfEle+=1;
    }
    
    int pop() {
        int ret=peekEle;
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st2.pop();
        peekEle=(st2.empty()?:st2.top());
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        numOfEle-=1;
        return ret;
    }
    
    int peek() {
        
        return peekEle;
    }
    
    bool empty() {
        
        return (numOfEle<=0?true:false);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */