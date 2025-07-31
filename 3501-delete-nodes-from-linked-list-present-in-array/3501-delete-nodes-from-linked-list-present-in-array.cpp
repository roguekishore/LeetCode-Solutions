class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int, bool> isPresent;
        for(int n : nums) {
            isPresent[n] = true;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = head;
        ListNode* prev = dummy;
        while(curr) {
            if(isPresent[curr->val]) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};