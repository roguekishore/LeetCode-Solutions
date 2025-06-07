class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        StackNode* newNode = new StackNode(x);
        if(!top) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }

    int pop() {
        if(!top) {
            return -1;
        }
        int n = top->data;
        top = top->next;
        return n;
        
    }

    MyStack() { top = NULL; }
};