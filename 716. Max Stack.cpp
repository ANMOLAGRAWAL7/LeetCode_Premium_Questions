/*
Design a max stack data structure that supports the stack operations and supports finding the stack's maximum element.

Implement the MaxStack class:

MaxStack() Initializes the stack object.
void push(int x) Pushes element x onto the stack.
int pop() Removes the element on top of the stack and returns it.
int top() Gets the element on the top of the stack without removing it.
int peekMax() Retrieves the maximum element in the stack without removing it.
int popMax() Retrieves the maximum element in the stack and removes it. If there is more than one maximum element, only remove the top-most one.
You must come up with a solution that supports O(1) for each top call and O(logn) for each other call.
*/
class MaxStack {
    #define pi pair<int,int>
    set<pi>val;
    set<pi>st;
    int id;
public:
    MaxStack() {
        id=0;
    }
    
    void push(int x) {
        st.insert({id,x});
        val.insert({x,id});
        id++;
    }
    
    int pop() {
        auto p=*st.rbegin();
        st.erase(p);
        val.erase({p.second,p.first});
        return p.second;
    }
    
    int top() {
        auto p=*st.rbegin();
        return p.second;
    }
    
    int peekMax() {
        auto p=*val.rbegin();
        return p.first;
    }
    
    int popMax() {
        auto p=*val.rbegin();
        val.erase(p);
        st.erase({p.second,p.first});
        return p.first;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
