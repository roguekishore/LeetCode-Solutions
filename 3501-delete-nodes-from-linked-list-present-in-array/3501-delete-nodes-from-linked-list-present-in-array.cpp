class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> isPresent;
        for(int n : nums) {
            isPresent.insert(n);
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = head;
        ListNode* prev = dummy;
        while(curr) {
            if(isPresent.count(curr->val)) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};