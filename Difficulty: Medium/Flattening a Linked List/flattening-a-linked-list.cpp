//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->bottom;
    }
    printf("\n");
}

Node* createLinkedList(vector<Node*>& v) {
    Node* head = new Node(0);
    Node* temp = head;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        temp->next = v[i];
        temp = temp->next;
    }
    return head->next;
}


// } Driver Code Ends

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeList(Node* head) {
        if(!head->next) {
            return head;
        }
        
        Node* head1 = head;
        Node* head2 = head->next;
        
        Node* dummyNode = new Node(0);
        Node* res = dummyNode;
        
        while(head1 && head2) {
            if(head1->data<head2->data) {
                Node* bottomNode = head1->bottom;
                res->bottom = head1;
                head1->next = NULL;
                head1->bottom = NULL;
                head1 = bottomNode;
                res = res->bottom;
            } else {
                Node* bottomNode = head2->bottom;
                res->bottom = head2;
                head2->next = NULL;
                head2->bottom = NULL;
                head2 = bottomNode;
                res = res->bottom;
            }
        }
        
        res->bottom = (head1) ? head1 : head2;
        head = dummyNode->bottom;
        return head;
    }
    Node *flatten(Node *root) {
        
        if(!root->next) {
            return root;
        }
        
        flatten(root->next);
        return mergeList(root);
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->bottom = newNode;
                temp = temp->bottom;
            }
            v[i] = head->bottom;
        }

        Solution ob;
        Node* list = createLinkedList(v);
        Node* head = ob.flatten(list);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends