queue<int> q,q1;


class MyStack {
public:
    MyStack() {
        while(!q.empty()) q.pop();
        while(!q1.empty()) q1.pop();
    }
    
    void push(int x) {
          q.push(x);
    }
    
    int pop() {
        int x=q.back();
        int sz=q.size();
        while(sz>1){
            q1.push(q.front());
            q.pop();
            sz--;
        }
        q.pop();                      
                           
        q=q1;
        while(!q1.empty()) q1.pop(); 
        return x;
    }
    
    int top() {
        int tp=q.back();
        return tp;  
    }
    
    bool empty() {
        return q.empty();
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