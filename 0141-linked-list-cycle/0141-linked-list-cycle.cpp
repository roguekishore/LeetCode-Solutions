/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        if(temp == NULL) {
            return false;
        }
        unordered_map<ListNode*, int> map;
        while(temp != NULL) {
            map[temp]++;
            if(map[temp] > 1) {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }
};