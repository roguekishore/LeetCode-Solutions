class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int> map;
        while(headA != nullptr) {
            map[headA]++;
            headA = headA->next;
        }
        while(headB != nullptr) {
            if(map[headB] > 0) {
                return headB;
            }
            headB = headB->next;
        }

        return NULL;
    }
};