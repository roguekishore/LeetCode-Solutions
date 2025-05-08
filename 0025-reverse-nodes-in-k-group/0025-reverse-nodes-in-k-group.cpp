class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }
        if(head->next == NULL) {
            return head;
        }

        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        int time = count/k;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevTail = dummy;
        ListNode* currHead = nullptr;

        for(int i=0 ; i<time ; i++) {
            int tempCount = k;

            while( tempCount>0 ) {
                
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;

                if(tempCount==k) {
                    currHead = prev;
                } 
                tempCount--;
            }

            prevTail->next = prev;
            currHead->next = curr;
            prevTail = currHead;
        }
        
        return dummy->next;
    }
};