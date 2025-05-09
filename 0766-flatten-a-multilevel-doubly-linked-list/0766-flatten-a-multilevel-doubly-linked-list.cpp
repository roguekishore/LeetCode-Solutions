class Solution {
public:
    Node* mergeList(Node* parent) {
        Node* nextNode = parent->next;
        parent->next = parent->child;
        parent->child->prev = parent;
        Node* curr = parent->child;
        parent->child = NULL;

        while (curr->next != NULL) {
            if (curr->child != NULL) {
                curr = mergeList(curr);
            }
            curr = curr->next;
        }

        curr->next = nextNode;
        if (nextNode)
            nextNode->prev = curr;
        return nextNode;
    }
    Node* flatten(Node* head) {
        if (!head)
            return head;
        Node* curr = head;

        while (curr != NULL) {
            if (curr->child != NULL) {
                Node* childNode = curr->child;
                while (childNode->next != NULL) {
                    childNode = childNode->next;
                }

                childNode->next = curr->next;
                if (curr->next != NULL)
                    curr->next->prev = childNode;

                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;
            }
            curr = curr->next;
        }

        return head;
    }
};