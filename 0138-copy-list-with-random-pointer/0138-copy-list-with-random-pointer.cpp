/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;

        while(temp) {
            Node* newNode = new Node(temp->val);
            Node* nextNode = temp->next;

            temp->next = newNode;
            newNode->next = nextNode;
            temp = nextNode;
        }

        temp = head;
        while(temp) {
            Node* randomNode = temp->random;
            if(randomNode == NULL) {
                temp->next->random = NULL;
            } else {
                temp->next->random = randomNode->next;
            }

            temp = temp->next->next;
        }
        temp = head;
        Node* dummyNode = new Node(0);
        Node* res = dummyNode;

        while(temp) {
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }
};