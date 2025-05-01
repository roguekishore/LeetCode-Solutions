class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> map;
        ListNode* temp = headA;
        while(temp != nullptr) {
            map[temp]++;
            temp = temp->next;
        }
        temp = headB;
        while(temp != nullptr) {
            if(map[temp] > 0) {
                return temp;
            }
            temp = temp->next;
        }

        return NULL;
    }
};