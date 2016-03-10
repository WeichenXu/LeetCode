class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        a.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while(a.size()>1){
            b.push(a.top());
            a.pop();
        }
        a.pop();
        while(b.size()){
            a.push(b.top());
            b.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        int res;
        while(a.size()){
            b.push(a.top());
            a.pop();
        }
        res = b.top();
        while(b.size()){
            a.push(b.top());
            b.pop();
        }
        return res;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return a.empty();
    }
private:
    // use two stacks to simulate the queue
    stack<int> a;
    stack<int> b;
};