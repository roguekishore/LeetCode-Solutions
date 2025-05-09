class Solution {
public:
    Node* interWeave(Node* head) {
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

    Node* hMap(Node* head) {
        unordered_map<Node*, Node*> map;
        Node* curr = head;

        while(curr) {
            Node* newNode = new Node(curr->val);
            map[curr] = newNode;
            curr = curr->next;
        }

        curr = head;
        while(curr) {
            Node* copyNode = map[curr];
            copyNode->next = map[curr->next];
            copyNode->random = map[curr->random];
            curr = curr->next;
        }

        return map[head];
    }
    Node* copyRandomList(Node* head) {
        return hMap(head);
    }
};