/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

void MyQueue:: push(int x)
{
    QueueNode* newNode = new QueueNode(x);
    if( !front && !rear ) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = rear->next;
    }
}

int MyQueue :: pop()
{
    if( !front ) {
        return -1;
    }
    QueueNode* tempNode = front;
    int v = tempNode->data;
    front = front->next;
    if( front==NULL ) {
        rear = NULL;
    }
    delete tempNode;
    return v;
}
