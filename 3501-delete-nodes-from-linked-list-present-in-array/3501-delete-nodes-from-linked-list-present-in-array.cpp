/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Use a hash set for quick lookup
        unordered_set<int> toRemove(nums.begin(), nums.end());

        // Dummy node to handle edge cases (like removing head)
        ListNode dummy(0);
        dummy.next = head;

        ListNode* current = &dummy;

        // Traverse the list
        while (current->next) {
            if (toRemove.count(current->next->val)) {
                // Remove node
                current->next = current->next->next;
            } else {
                // Move forward
                current = current->next;
            }
        }

        return dummy.next;
    }
};
